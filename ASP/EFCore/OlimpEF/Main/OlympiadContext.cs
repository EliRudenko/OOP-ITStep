using Microsoft.EntityFrameworkCore;
using Models;

namespace OlympiadEFCore
{
    public class OlympiadContext : DbContext
    {
        public DbSet<Participant> Participants { get; set; }
        public DbSet<Country> Countries { get; set; }
        public DbSet<City> Cities { get; set; }
        public DbSet<Sport> Sports { get; set; }
        public DbSet<Olympiad> Olympiads { get; set; }
        public DbSet<Result> Results { get; set; }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseSqlServer(@"Server=ANDREYPC;Database=OlympiadDb;Integrated Security=SSPI;TrustServerCertificate=true");
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            // Country
            modelBuilder.Entity<Country>()
                .HasKey(c => c.Id);
            modelBuilder.Entity<Country>()
                .HasIndex(c => c.Name)
                .IsUnique();
            modelBuilder.Entity<Country>()
                .Property(c => c.Name)
                .HasMaxLength(100)
                .IsRequired();

            // City
            modelBuilder.Entity<City>()
                .HasKey(c => c.Id);
            modelBuilder.Entity<City>()
                .HasOne(c => c.Country)
                .WithMany()  
                .HasForeignKey(c => c.CountryId);

            // Participant
            modelBuilder.Entity<Participant>()
                .HasKey(p => p.Id);
            modelBuilder.Entity<Participant>()
                .Property(p => p.Name)
                .IsRequired()
                .HasMaxLength(100);
            modelBuilder.Entity<Participant>()
                .ToTable(t => t.HasCheckConstraint("CK_Participant_Name", "LEN(Name)>0"));
            modelBuilder.Entity<Participant>()
                .Property(p => p.Surname)
                .IsRequired()
                .HasMaxLength(100);
            modelBuilder.Entity<Participant>()
                .ToTable(t => t.HasCheckConstraint("CK_Participant_Surname", "LEN(Surname)>0"));
            modelBuilder.Entity<Participant>()
                .Property(p => p.Birthday)
                .IsRequired();
            modelBuilder.Entity<Participant>()
                .HasOne(p => p.City)
                .WithMany()
                .HasForeignKey(p => p.CityId)
                .OnDelete(DeleteBehavior.Restrict);
            modelBuilder.Entity<Participant>()
                .HasOne(p => p.Sport)
                .WithMany()
                .HasForeignKey(p => p.SportId)
                .OnDelete(DeleteBehavior.Restrict);
            modelBuilder.Entity<Participant>()
                .HasOne(p => p.Olympiad)
                .WithMany()
                .HasForeignKey(p => p.OlympiadId)
                .OnDelete(DeleteBehavior.Cascade);

            // Result
            modelBuilder.Entity<Result>()
                .HasKey(r => r.Id);
            modelBuilder.Entity<Result>()
                .Property(r => r.Place)
                .IsRequired();
            modelBuilder.Entity<Result>()
                .ToTable(t => t.HasCheckConstraint("CK_Result_Place", "Place>0 AND Place<=64"));
            modelBuilder.Entity<Result>()
                .HasOne(r => r.Participant)
                .WithOne()
                .HasForeignKey<Result>(r => r.ParticipantId)
                .OnDelete(DeleteBehavior.Restrict);

            // Sport
            modelBuilder.Entity<Sport>()
                .HasKey(s => s.Id);
            modelBuilder.Entity<Sport>()
                .HasIndex(s => s.Name)
                .IsUnique();
            modelBuilder.Entity<Sport>()
                .Property(s => s.Name)
                .IsRequired()
                .HasMaxLength(100);
            modelBuilder.Entity<Sport>()
                .ToTable(t => t.HasCheckConstraint("CK_Sport_Name", "LEN(Name)>0"));


            // Olympiad
            modelBuilder.Entity<Olympiad>()
                .HasKey(o => o.Id);
            modelBuilder.Entity<Olympiad>()
                .Property(o => o.Year)
                .IsRequired();
            modelBuilder.Entity<Olympiad>()
                .ToTable(t => t.HasCheckConstraint("CK_Olympiad_Year", "Year>=1896 AND Year<=2024"));
            modelBuilder.Entity<Olympiad>()
                .ToTable(t => t.HasCheckConstraint("CK_Olympiad_Leap_Year", "Year % 4 = 0"));
            modelBuilder.Entity<Olympiad>()
                .Property(o => o.Season)
                .IsRequired();
            modelBuilder.Entity<Olympiad>()
                .ToTable(t => t.HasCheckConstraint("CK_Olympiad_Season", "Season = 'Summer' OR Season = 'Winter'"));
            modelBuilder.Entity<Olympiad>()
                .HasOne(o => o.City)
                .WithMany() 
                .HasForeignKey(o => o.CityId)
                .OnDelete(DeleteBehavior.NoAction);

            modelBuilder.Entity<Olympiad>()
                .HasMany(o => o.Participants)
                .WithOne(p => p.Olympiad)
                .HasForeignKey(p => p.OlympiadId);
        }
    }
}
