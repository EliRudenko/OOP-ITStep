using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Configuration;
using Models;

namespace IT_Employee_WinForms
{
    public class EmployeeContext : DbContext
    {
        public DbSet<Employee> Employees { get; set; } 
        public DbSet<Position> Positions { get; set; }  
        public DbSet<User> Users { get; set; }

        public static readonly List<string> pos_constraints = new List<string> { "Employee", "Manager", "Developer", "Designer" };

        private static readonly DbContextOptions<EmployeeContext> _options;

        static EmployeeContext()
        {
            var builder = new ConfigurationBuilder()
                .SetBasePath(Directory.GetCurrentDirectory())
                .AddJsonFile("appsettings.json");

            var config = builder.Build();
            string? connectionString = config.GetConnectionString("DefaultConnection");

            var optionsBuilder = new DbContextOptionsBuilder<EmployeeContext>();
            if(connectionString != null )
                _options = optionsBuilder.UseSqlServer(connectionString).Options;
        }

        public EmployeeContext() : base(_options) {
            Database.EnsureCreated();
        }

        public EmployeeContext(DbContextOptions<EmployeeContext> options) : base(options) { }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            if (!optionsBuilder.IsConfigured)
                optionsBuilder.UseLazyLoadingProxies();
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Position>()
                .HasKey(p => p.Id);

            modelBuilder.Entity<Position>()
                .Property(p => p.Name)
                .IsRequired()
                .HasMaxLength(40)
                .HasDefaultValue("Employee");

            modelBuilder.Entity<Position>()
                .HasData(
                    new Position { Id = 1, Name = "Employee" },
                    new Position { Id = 2, Name = "Manager" },
                    new Position { Id = 3, Name = "Developer" },
                    new Position { Id = 4, Name = "Designer" }
                );

            modelBuilder.Entity<Employee>()
                .HasKey(e => e.Id);

            modelBuilder.Entity<Employee>()
                .Property(e => e.FirstName)
                .IsRequired()
                .HasMaxLength(40);

            modelBuilder.Entity<Employee>()
                .Property(e => e.LastName)
                .IsRequired()
                .HasMaxLength(40);

            modelBuilder.Entity<Employee>()
                .HasOne(e => e.Position)
                .WithMany(p=>p.Employees)  
                .HasForeignKey(e => e.PositionId);

            modelBuilder.Entity<User>()
                .HasKey(e => e.Id);

            modelBuilder.Entity<User>()
                .HasIndex(e => e.Login)
                .IsUnique();

            modelBuilder.Entity<User>()
                .Property(e => e.Login)
                .IsRequired()
                .HasMaxLength(40);

            modelBuilder.Entity<User>()
                .Property(e => e.Password)
                .IsRequired()
                .HasMaxLength(20);

        }
    }
}
