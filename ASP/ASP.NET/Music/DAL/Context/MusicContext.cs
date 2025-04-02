using Microsoft.EntityFrameworkCore;
using MusicPortal_Layered_ASP.DLL.Entities;

namespace MusicPortal_Layered_ASP.DLL.Context
{
    public class MusicContext : DbContext
    {
        public DbSet<User> Users { get; set; }
        public DbSet<Genre> Genres { get; set; }
        public DbSet<Song> Songs { get; set; }

        public MusicContext(DbContextOptions<MusicContext> options) : base(options) { }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<User>()
                .HasIndex(u => u.Username)
                .IsUnique();
        }
    }
}
