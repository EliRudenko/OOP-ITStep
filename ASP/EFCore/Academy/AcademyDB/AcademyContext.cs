using Microsoft.EntityFrameworkCore;
using Models;

namespace AcademyDB
{
    public class AcademyContext : DbContext
    {
        public DbSet <Teacher> Teachers { get; set; }
        public DbSet<Subject> Subjects { get; set; }
        public DbSet<Curator> Curators { get; set; }
        public DbSet <Faculty> Faculties { get; set; }
        public DbSet <Department> Departments { get; set; }
        public DbSet<Group> Groups { get; set; }
        public DbSet<Lecture> Lectures { get; set; }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseSqlServer(@"Server=ANDREYPC;Database=AcademyDB;Integrated Security=SSPI;TrustServerCertificate=true");
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            //Faculty
            modelBuilder.Entity<Faculty>()
                .HasKey(f => f.Id);
            modelBuilder.Entity<Faculty>()
                .Property(f => f.Financing)
                .HasColumnType("money")
                .IsRequired()
                .HasDefaultValue(0);
            modelBuilder.Entity<Faculty>()
                .Property(f => f.Name)
                .HasMaxLength(100)
                .IsRequired();
            modelBuilder.Entity<Faculty>()
                .HasIndex(f => f.Name)
                .IsUnique();
            modelBuilder.Entity<Faculty>()
                .ToTable(f => f.HasCheckConstraint("CK_Faculty_Financing", "[Financing] >= 0"));

            //Curator
            modelBuilder.Entity<Curator>()
                .HasKey(c => c.Id);
            modelBuilder.Entity<Curator>()
                .Property(c => c.Name)
                .HasMaxLength(100)
                .IsRequired();
            modelBuilder.Entity<Curator>()
                .Property(c=>c.Surname)
                .HasMaxLength(100)
                .IsRequired();

            //Subject
            modelBuilder.Entity<Subject>()
                .HasKey(s => s.Id);
            modelBuilder.Entity<Subject>()
                .HasIndex(s => s.Name)
                .IsUnique();
            modelBuilder.Entity<Subject>()
                .Property(s => s.Name)
                .HasMaxLength(100)
                .IsRequired();


            //Teacher
            modelBuilder.Entity<Teacher>()
                .HasKey(t => t.Id);
            modelBuilder.Entity<Teacher>()
                .Property(t => t.Name)
                .HasMaxLength(100)
                .IsRequired();
            modelBuilder.Entity<Teacher>()
                .Property(t => t.Surname)
                .HasMaxLength(100)
                .IsRequired();
            modelBuilder.Entity<Teacher>()
                .Property(t => t.Salary)
                .HasColumnType("money")
                .IsRequired();
            modelBuilder.Entity<Teacher>()
                .ToTable(t => t.HasCheckConstraint("CK_Teacher_Salary_Positive", "[Salary] > 0"));

            //Department
            modelBuilder.Entity<Department>()
                .HasKey(d => d.Id);
            modelBuilder.Entity<Department>()
                .Property(d => d.Financing)
                .HasColumnType("money")
                .IsRequired()
                .HasDefaultValue(0);
            modelBuilder.Entity<Department>()
                .ToTable(d => d.HasCheckConstraint("CK_Department_Financing", "[Financing] >= 0"));
            modelBuilder.Entity<Department>()
                .Property(d=>d.Name)
                .HasMaxLength(100)
                .IsRequired();
            modelBuilder.Entity<Department>()
                .HasOne(d => d.Faculty)
                .WithMany()
                .HasForeignKey(d => d.FacultyId)
                .OnDelete(DeleteBehavior.Cascade);

            //Group
            modelBuilder.Entity<Group>()
                .HasKey(g => g.Id);
            modelBuilder.Entity<Group>()
                .Property(g => g.Name)
                .HasMaxLength(10)
                .IsRequired();
            modelBuilder.Entity<Group>()
                .HasIndex(g => g.Name)
                .IsUnique();
            modelBuilder.Entity<Group>()
                .Property(g => g.Year)
                .IsRequired();
            modelBuilder.Entity<Group>()
                .ToTable(g => g.HasCheckConstraint("CK_Group_Year", "[Year] >= 1 AND [Year] <= 5"));
            modelBuilder.Entity<Group>()
                .HasOne(g => g.Department)
                .WithMany()
                .HasForeignKey(g => g.DepartmentId);

            //GroupsCurators
            modelBuilder.Entity<Group>()
                .HasMany(g => g.Curators)
                .WithMany(c => c.Groups)
                .UsingEntity(j => j.ToTable("GroupsCurators"));

            //Lecture
            modelBuilder.Entity<Lecture>()
                .HasKey(l => l.Id);
            modelBuilder.Entity<Lecture>()
                .Property(l => l.LectureRoom)
                .IsRequired();

            modelBuilder.Entity<Lecture>()
                .HasOne(l => l.Subject)
                .WithMany(l => l.Lectures)
                .HasForeignKey(l => l.SubjectId);
            modelBuilder.Entity<Lecture>()
                .HasOne(l => l.Teacher)
                .WithMany(l => l.Lectures)
                .HasForeignKey(l => l.TeacherId);

            //GroupsLectures
            modelBuilder.Entity<Group>()
                .HasMany(g => g.Lectures)
                .WithMany(l => l.Groups)
                .UsingEntity(j => j.ToTable("GroupsLectures"));

        }
    }
}
