using Microsoft.EntityFrameworkCore;

namespace CRUD_Students_Groups_ASP.Models
{
    public class UniversityContext:DbContext
    {
        public DbSet<Student> Students { get; set; }
        public DbSet<Group> Groups { get; set; }

        public UniversityContext(DbContextOptions<UniversityContext> options) : base(options) { }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Group>()
                .HasIndex(g => g.Name)
                .IsUnique();

            modelBuilder.Entity<Student>()
                .HasOne(s=>s.Group)
                .WithMany()
                .HasForeignKey(s=>s.GroupId)
                .OnDelete(DeleteBehavior.Restrict);

        }

    }
}
