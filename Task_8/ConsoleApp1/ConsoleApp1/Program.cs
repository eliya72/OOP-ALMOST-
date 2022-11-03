// See https://aka.ms/new-console-template for more information
class Program
{
    abstract class Weapons
    {
        protected string Name { get; set; }
        protected int Ammo { get; set; }
        protected int Capacity { get; set; }
        protected int Length { get; set; }
        protected int Thickness { get; set; }


        public virtual void display()
        {
            Console.WriteLine($"{Name}, caliber: {Ammo}:{Capacity}, caliber2: {Length}:{Thickness}");
        }

        public int Price()
        {
            return (int)(Ammo + (Capacity/Ammo));
        }
    }

    class ColdWeapons : Weapons
    {
        protected string NameOfColdWeapons { get; set; }

        public ColdWeapons(string NameColdWeapons, string Name, int Ammo, int Capacity)
        {
            this.NameOfColdWeapons = NameColdWeapons;
            this.Name = Name;
            this.Ammo = Ammo;
            this.Capacity = Capacity;
        }
        public override void display()
        {
            Console.WriteLine($"{Name}, caliber: {Ammo}:{Capacity}\n\tFire Weapons = {NameOfColdWeapons}");
        }

    }

    class FireWeapons : ColdWeapons
    {
        protected string NameOfFireWeapons { get; set; }

        public FireWeapons(string NameFireWeapons, string NameColdWeapons, string Name, int Length, int Thickness) : base(NameColdWeapons, Name, Min, Sec)
        {
            this.NameOfFireWeapons = NameFireWeapons;
            this.NameOfColdWeapons = NameColdWeapons;
            this.Name = Name;
            this.Length = Length;
            this.Thickness = Thickness;
        }
        public override void display()
        {
            Console.WriteLine($"{Name}, duration: {Length}:{Thickness}\n\tCold Weapon = {NameOfColdWeapons}, Fire Weapon = {NameOfFireWeapons}");
        }

    }


    static void Main(string[] args)
    {
        int Unit = 0;
        List<Weapons> quantity = new List<Weapons>
        {
            new ColdWeapons("Cold","Knife", 10, 2),
            new FireWeapons("Fire", "Knife", "Rifle", 60, 2)
        }; //список покажчиків на базовий клас

        foreach (Weapons count in quantity)
        {
            count.display();
            Unit += count.Price();
        }

        Console.WriteLine($"\nA whole price per unit:\t{Unit}");

        Console.ReadKey();
    }
}
