using Microsoft.EntityFrameworkCore;

namespace UniversityMVC.Models
{
    public class UniversityContext:DbContext
    {
        public DbSet<Student> Students { get; set; }
        public DbSet<Subject> Subjects { get; set; }
        public DbSet<Group> Groups {  get; set; }
        public DbSet<Teacher> Teachers { get; set; }
        public DbSet<SubjectsGroups> SubjectsGroups { get; set; }

        public UniversityContext(DbContextOptions<UniversityContext> options) : base(options) { }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            //Student
            modelBuilder.Entity<Student>()
                .HasKey(s => s.Id);
            modelBuilder.Entity<Student>()
                .Property(s => s.Name)
                .IsRequired()
                .HasMaxLength(50);
            modelBuilder.Entity<Student>()
                .Property(s=>s.LastName)
                .IsRequired()
                .HasMaxLength(50);

            //Subject
            modelBuilder.Entity<Subject>()
                .HasKey(s => s.Id);
            modelBuilder.Entity<Subject>()
                .Property(s => s.Name)
                .IsRequired()
                .HasMaxLength(50);

            //Teacher
            modelBuilder.Entity<Teacher>()
                .HasKey(t => t.Id);
            modelBuilder.Entity<Teacher>()
                .Property(t => t.Name)
                .IsRequired()
                .HasMaxLength(50);
            modelBuilder.Entity<Teacher>()
                .Property(t => t.LastName)
                .IsRequired()
                .HasMaxLength(50);

            //Group
            modelBuilder.Entity<Group>()
                .HasKey(g => g.Id);
            modelBuilder.Entity<Group>()
                .Property(g => g.Name)
                .IsRequired()
                .HasMaxLength(50);

            //Students to Group
            modelBuilder.Entity<Student>()
                .HasOne(s => s.Group)
                .WithMany(g => g.Students)
                .HasForeignKey(s => s.GroupId);

            //SubjectsGroups

            modelBuilder.Entity<SubjectsGroups>()
                .HasOne(sg => sg.Teacher)
                .WithMany(t => t.SubjectsGroups)  
                .HasForeignKey(sg => sg.TeacherId)
                .OnDelete(DeleteBehavior.Cascade);

            modelBuilder.Entity<SubjectsGroups>()
                .HasOne(sg=>sg.Subject)
                .WithMany(s =>s.SubjectsGroups)
                .HasForeignKey(sg=>sg.SubjectId)
                .OnDelete(DeleteBehavior.Cascade);

            modelBuilder.Entity<SubjectsGroups>()
                .HasOne(sg=>sg.Group)
                .WithMany(g=>g.SubjectsGroups)
                .HasForeignKey(sg=>sg.GroupId)
                .OnDelete(DeleteBehavior.Cascade);


        }
    }
}
