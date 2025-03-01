using System;
using System.Collections.Generic;
using Microsoft.EntityFrameworkCore;

namespace DBFirst;

public partial class LibraryContext : DbContext
{
    public LibraryContext()
    {
    }

    public LibraryContext(DbContextOptions<LibraryContext> options)
        : base(options)
    {
    }

    public virtual DbSet<Author> Authors { get; set; }

    public virtual DbSet<Book> Books { get; set; }

    public virtual DbSet<Group> Groups { get; set; }

    public virtual DbSet<Student> Students { get; set; }

    public virtual DbSet<Temp> Temps { get; set; }

    protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
#warning To protect potentially sensitive information in your connection string, you should move it out of source code. You can avoid scaffolding the connection string by using the Name= syntax to read it from configuration - see https://go.microsoft.com/fwlink/?linkid=2131148. For more guidance on storing connection strings, see https://go.microsoft.com/fwlink/?LinkId=723263.
        => optionsBuilder.UseSqlite("Data Source=C:\\\\\\\\Users\\\\\\\\morri\\\\\\\\OneDrive\\\\\\\\Рабочий стол\\\\\\\\Library.db");

    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        modelBuilder.Entity<Group>(entity =>
        {
            entity.HasIndex(e => e.Name, "IX_Groups_Name").IsUnique();

            entity.Property(e => e.Count).HasDefaultValue(10);
        });

        modelBuilder.Entity<Student>(entity =>
        {
            entity.Property(e => e.Age).HasDefaultValue(17);
            entity.Property(e => e.IdGroups).HasColumnName("Id_Groups");

            entity.HasOne(d => d.IdGroupsNavigation).WithMany(p => p.Students)
                .HasForeignKey(d => d.IdGroups)
                .OnDelete(DeleteBehavior.SetNull);
        });

        modelBuilder.Entity<Temp>(entity =>
        {
            entity
                .HasNoKey()
                .ToTable("Temp");

            entity.Property(e => e.AuthorsId).HasColumnName("Authors_Id");
            entity.Property(e => e.BooksId).HasColumnName("Books_Id");

            entity.HasOne(d => d.Authors).WithMany()
                .HasForeignKey(d => d.AuthorsId)
                .OnDelete(DeleteBehavior.SetNull);

            entity.HasOne(d => d.Books).WithMany()
                .HasForeignKey(d => d.BooksId)
                .OnDelete(DeleteBehavior.SetNull);
        });

        OnModelCreatingPartial(modelBuilder);
    }

    partial void OnModelCreatingPartial(ModelBuilder modelBuilder);
}
