namespace RemoteControlCar
{
    public class RemoteControlCar
    {
        puclic RemoteControlCar(Motor motor, Chassis chassis, Telemetry telemetry, RunningGear runningGear = null)
        {
        }
        public class RunningGear { }
        public class Telemetry { }
        public class Chassis { }
        public class Motor { }
    }
}
namespace RedRemoteControlCarTeam
{
    using RemoteControlcar;

    public RemoteControlCar(Motor motor, Chassis chassis, Telemetry telemetry, RunningGear runningGear) { }
}

namespace BlueRemoteControlCarTeam
{
    using RemoteControlCar;

    var blueCar = new RemoteControlCar(Motor motor, Chassis chassis, Telemetry telemetry: q

}

namespace Combined
{
    using Red = RedRemoteControlCarTeam;
    using Blue = BlueRemoteControlCarTeam;

    public static class CarBuilder
    {

        public static Red.RemoteControlCar BuildRed() => new Red.RemoteControlCar(
                new Red.RemoteControlCar.Motor(),
                new Red.RemoteControlCar.Chassis(),
                new Red.RemoteControlCar.Telemetry(),
                new Red.RemoteControlCar.RunningGear()
            );

        public static Blue.RemoteControlCar BuildBlue() => new Blue.RemoteControlCar(
                new Blue.RemoteControlCar.Motor(),
                new Blue.RemoteControlCar.Chassis(),
                new Blue.RemoteControlCar.Telemetry()
            );
    }
}
