namespace Models
{
    public class Country
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public string Capital { get; set; }
        public int Population { get; set; }
        public double Square { get; set; }
        public virtual Continent Continent {get;set;}
    }
}
