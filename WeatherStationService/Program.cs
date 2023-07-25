using Topshelf;
using WeatherStationServices;

namespace WinService
{
    class WeatherStation
    {
        static void Main(string[] args)
        {
            

            var exitCode = HostFactory.Run(x =>
            {
                x.Service<WeatherStationService>(s =>
                {
                    s.ConstructUsing(WeatherStationService => new WeatherStationService());
                    s.WhenStarted(WeatherStationService => WeatherStationService.OnStart());
                    s.WhenStopped(WeatherStationService => WeatherStationService.OnStop());
                });

                x.RunAsLocalSystem();
                x.SetServiceName("Weather Station Lookout Service");
                x.SetDisplayName("Weather Station Lookout Service");
                x.SetDescription("Provides interface between IoT Weather Station device and SQL Server Database for saving measurements recordings for later analysis.");
            });

            int exitCodeValue = (int)Convert.ChangeType(exitCode, exitCode.GetTypeCode());
            Environment.ExitCode = exitCodeValue;
        }
    }
}