using System;
using InterfaceHierarchy;

namespace TransportsHierarchy
{
    public abstract class Transport
    {
        public abstract string Name { get; }
        public abstract string Action { get; }

        public virtual void Move()
        {
            Console.WriteLine("{0} is {1}", Name, Action);
        }
    }
}

namespace InterfaceHierarchy
{
    public interface IGround
    {
        void BuildGroundRoute();
    }

    public interface IWater
    {
        void BuildWaterRoute();
    }

    public interface IAir
    {
        void BuildAirRoute();
    }
}

namespace TransportsHierarchy.GroundTransport
{
    public class Automobile : Transport, IGround
    {
        private static readonly string name = "Automobile";
        public override string Name => name;
        private static readonly string action = "Moving";
        public override string Action => action;

        public void BuildGroundRoute()
        {
            Console.WriteLine("Ground route for {0} has been built", Name);
        }
    }

    public class Railroad : Transport, IGround
    {
        private static readonly string name = "Railroad";
        public override string Name => name;
        private static readonly string action = "Moving";
        public override string Action => action;

        public void BuildGroundRoute()
        {
            Console.WriteLine("Ground route for {0} has been built", Name);
        }
    }

    public class HorseDrawn : Transport, IGround
    {
        private static readonly string name = "Horse-drawn";
        public override string Name => name;
        private static readonly string action = "Moving";
        public override string Action => action;

        public void BuildGroundRoute()
        {
            Console.WriteLine("Ground route for {0} has been built", Name);
        }
    }
}

namespace TransportsHierarchy.WaterTransport
{
    public class Tanker : Transport, IWater
    {
        private static readonly string name = "Tanker";
        public override string Name => name;
        private static readonly string action = "Swimming";
        public override string Action => action;

        public void BuildWaterRoute()
        {
            Console.WriteLine("Water route for {0} has been built", Name);
        }
    }

    public class Boat : Transport, IWater
    {
        private static readonly string name = "Boat";
        public override string Name => name;
        private static readonly string action = "Swimming";
        public override string Action => action;

        public void BuildWaterRoute()
        {
            Console.WriteLine("Water route for {0} has been built", Name);
        }
    }

    public class Motorship : Transport, IWater
    {
        private static readonly string name = "Motorship";
        public override string Name => name;
        private static readonly string action = "Swimming";
        public override string Action => action;

        public void BuildWaterRoute()
        {
            Console.WriteLine("Water route for {0} has been built", Name);
        }
    }
}

namespace TransportsHierarchy.AirTransport
{
    public class Airplane : Transport, IAir
    {
        private static readonly string name = "Airplane";
        private static readonly string action = "Flying";
        public override string Action => action;
        public override string Name => name;

        public void BuildAirRoute()
        {
            Console.WriteLine("Air route for {0} has been built", Name);
        }
    }

    public class Helicopter : Transport, IAir
    {
        private static readonly string name = "Helicopter";
        private static readonly string action = "Flying";
        public override string Action => action;
        public override string Name => name;

        public void BuildAirRoute()
        {
            Console.WriteLine("Air route for {0} has been built", Name);
        }
    }

    public class Airship : Transport, IAir
    {
        private static readonly string name = "Airship";
        private static readonly string action = "Flying";
        public override string Action => action;
        public override string Name => name;

        public void BuildAirRoute()
        {
            Console.WriteLine("Air route for {0} has been built", Name);
        }
    }
}

namespace ClientClass
{
    using TransportsHierarchy;
    using TransportsHierarchy.AirTransport;
    using TransportsHierarchy.GroundTransport;
    using TransportsHierarchy.WaterTransport;

    public class Client
    {
        private Transport transport;

        private Transport CreateTransport()
        {
            Console.WriteLine("Choose an hierarchy of your transport (Ground, Water, Air):");
            string hierarchy = Console.ReadLine();

            Console.WriteLine("Choose a transport that's included in your hierarchy:");
            string transportOption = Console.ReadLine();

            transport = hierarchy switch
            {
                "Ground" => transportOption switch
                {
                    "Automobile" => new Automobile(),
                    "Railroad" => new Railroad(),
                    "Horse-drawn" => new HorseDrawn(),
                    _ => throw new Exception("Invalid transport option for Ground hierarchy.")
                },
                "Water" => transportOption switch
                {
                    "Boat" => new Boat(),
                    "Tanker" => new Tanker(),
                    "Motorship" => new Motorship(),
                    _ => throw new Exception("Invalid transport option for Water hierarchy.")
                },
                "Air" => transportOption switch
                {
                    "Airplane" => new Airplane(),
                    "Helicopter" => new Helicopter(),
                    "Airship" => new Airship(),
                    _ => throw new Exception("Invalid transport option for Air hierarchy.")
                },
                _ => throw new Exception("There is no such hierarchy option.")
            };

            return transport;
        }

        private void Routing()
        {
            if (transport is IGround ground)
                ground.BuildGroundRoute();
            else if (transport is IAir air)
                air.BuildAirRoute();
            else if (transport is IWater water)
                water.BuildWaterRoute();

            transport.Move();
        }

        public void Begin()
        {
            CreateTransport();
            Routing();
        }
    }
}

class Program
{
    static void Main()
    {
        Client client = new Client();
        client.Begin();
    }
}
