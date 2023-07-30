using System.Configuration;
using Dapper;
using System.Net.Sockets;
using System.Data;
using System.Timers;

namespace WeatherStationServices
{
    public class WeatherStationService
    {
        private readonly System.Timers.Timer _timer;

        private readonly string ip = ConfigurationManager.AppSettings["ip"];
        private readonly int port = Int32.Parse(ConfigurationManager.AppSettings["port"]);
        private readonly int frecuency = Int32.Parse(ConfigurationManager.AppSettings["frecuency"]);
        public WeatherStationService()
        {

            Console.WriteLine("TCP/IP connection: {0},{1}", ip, port);

            _timer = new System.Timers.Timer(frecuency) { AutoReset = true };
            _timer.Elapsed += TimerElapsed;

        }

        private void TimerElapsed(object? sender, ElapsedEventArgs e)
        {
            TcpClient client = new TcpClient(ip, port);

            while (!client.Connected)
            {
                try
                {
                    client.Connect(ip, port);
                }
                catch (ArgumentNullException f)
                {
                    Console.WriteLine("ArgumentNullException: {0}", f);
                }
                catch (SocketException f)
                {
                    Console.WriteLine("SocketException: {0}", f);
                }

                if (client.Connected)
                {
                    while (!(client.Available > 0))
                    {
                        if (!client.Connected)
                        {
                            Console.WriteLine("Connection Lost...");
                            break;
                        }
                    }
                }
            }

            if (client.Connected)
            {
                NetworkStream stream = client.GetStream();

                Byte[] data = new Byte[256];

                String responseData = String.Empty;

                responseData = System.Text.Encoding.ASCII.GetString(data, 0, stream.Read(data, 0, data.Length));

                Console.WriteLine("Received: {0}", responseData);

                insertRecord(responseData);

                stream.Close();
            }

            client.Close();
        }

        private void insertRecord(string responseData)
        {
            var connectionString = ConfigurationManager.ConnectionStrings["IoT_Weather"].ConnectionString;

            string[] arr = responseData.Split(";");

            Measurement m = new Measurement
            {
                Timestamp = new DateTime(Int32.Parse(arr[2]), Int32.Parse(arr[1]), Int32.Parse(arr[0]), Int32.Parse(arr[3]), Int32.Parse(arr[4]), Int32.Parse(arr[5])),
                Temperature = float.Parse(arr[6]),
                Humidity = float.Parse(arr[7]),
            };

            using (IDbConnection connection = new System.Data.SqlClient.SqlConnection(connectionString))
            {
                connection.Execute("INSERT INTO Measurement (Timestamp, Temperature, Humidity) VALUES (@Timestamp, @Temperature, @Humidity)", m);
            }
        }

        public class Measurement
        {
            public int id { get; set; }
            public DateTime Timestamp { get; set; }
            public float Temperature { get; set; }
            public float Humidity { get; set; }
        } 

        public void OnStart()
        {
            _timer.Start();
            //throw new NotImplementedException();
        }
        public void OnStop()
        {
            _timer.Stop();
            //throw new NotImplementedException();
        }
    }
}
