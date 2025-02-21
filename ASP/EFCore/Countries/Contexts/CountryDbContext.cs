using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Configuration;
using Models;

public class CountryDbContext : DbContext
{
    public DbSet<Continent> Continents { get; set; }
    public DbSet<Country> Countries { get; set; }

    static DbContextOptions<CountryDbContext> _options;
    static CountryDbContext()
    {
        var builder = new ConfigurationBuilder();
        builder.SetBasePath(Directory.GetCurrentDirectory());
        builder.AddJsonFile("appsettings.json");
        var config = builder.Build();

        string connectionString = config.GetConnectionString("DefaultConnection");

        var optionsBuilder = new DbContextOptionsBuilder<CountryDbContext>();
        _options = optionsBuilder.UseSqlServer(connectionString).Options;
    }
    public CountryDbContext() : base(_options)

    {
        if (Database.EnsureCreated())
        {
            var asiaCont = new Continent { Name = "Asia" };
            var africaCont = new Continent { Name = "Africa" };
            var europeCont = new Continent { Name = "Europe" };
            var americaCont = new Continent { Name = "America" };

            Continents?.AddRange(asiaCont, africaCont, europeCont, americaCont);
            SaveChanges();

            var countries = new List<Country>
            {
                new Country { Name = "China", Capital = "Beijing", Population = 1444216107, Square = 9596961, Continent = asiaCont },
                new Country { Name = "India", Capital = "New Delhi", Population = 1393409038, Square = 3287263, Continent = asiaCont },
                new Country { Name = "Japan", Capital = "Tokyo", Population = 126050796, Square = 377975, Continent = asiaCont },
                new Country { Name = "Egypt", Capital = "Cairo", Population = 104258327, Square = 1002450, Continent = africaCont },
                new Country { Name = "Nigeria", Capital = "Abuja", Population = 206139589, Square = 923768, Continent = africaCont },
                new Country { Name = "France", Capital = "Paris", Population = 67391582, Square = 551695, Continent = europeCont },
                new Country { Name = "Germany", Capital = "Berlin", Population = 83190556, Square = 357022, Continent = europeCont },
                new Country { Name = "Brazil", Capital = "Brasília", Population = 212559417, Square = 8515767, Continent = americaCont },
                new Country { Name = "USA", Capital = "Washington D.C.", Population = 331002651, Square = 9833517, Continent = americaCont },
                new Country { Name = "Argentina", Capital = "Buenos Aires", Population = 45195774, Square = 2780400, Continent = americaCont }
            };

            Countries?.AddRange(countries);
            SaveChanges();
        }
    }


    protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
    {
        optionsBuilder.UseLazyLoadingProxies();
    }
}
