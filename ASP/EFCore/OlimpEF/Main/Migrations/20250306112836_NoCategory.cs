using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace Main.Migrations
{
    /// <inheritdoc />
    public partial class NoCategory : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_Participants_SportsCategories_SportCategoryId",
                table: "Participants");

            migrationBuilder.DropForeignKey(
                name: "FK_Results_SportsCategories_SportId",
                table: "Results");

            migrationBuilder.DropTable(
                name: "SportsCategories");

            migrationBuilder.DropIndex(
                name: "IX_Results_SportId",
                table: "Results");

            migrationBuilder.DropIndex(
                name: "IX_Participants_SportCategoryId",
                table: "Participants");

            migrationBuilder.DropColumn(
                name: "SportCategoryId",
                table: "Participants");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AddColumn<int>(
                name: "SportCategoryId",
                table: "Participants",
                type: "int",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.CreateTable(
                name: "SportsCategories",
                columns: table => new
                {
                    Id = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    OlympiadId = table.Column<int>(type: "int", nullable: false),
                    SportId = table.Column<int>(type: "int", nullable: false),
                    ParticipantsCount = table.Column<int>(type: "int", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_SportsCategories", x => x.Id);
                    table.ForeignKey(
                        name: "FK_SportsCategories_Olympiads_OlympiadId",
                        column: x => x.OlympiadId,
                        principalTable: "Olympiads",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                    table.ForeignKey(
                        name: "FK_SportsCategories_Sports_SportId",
                        column: x => x.SportId,
                        principalTable: "Sports",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateIndex(
                name: "IX_Results_SportId",
                table: "Results",
                column: "SportId");

            migrationBuilder.CreateIndex(
                name: "IX_Participants_SportCategoryId",
                table: "Participants",
                column: "SportCategoryId");

            migrationBuilder.CreateIndex(
                name: "IX_SportsCategories_OlympiadId",
                table: "SportsCategories",
                column: "OlympiadId");

            migrationBuilder.CreateIndex(
                name: "IX_SportsCategories_SportId",
                table: "SportsCategories",
                column: "SportId",
                unique: true);

            migrationBuilder.AddForeignKey(
                name: "FK_Participants_SportsCategories_SportCategoryId",
                table: "Participants",
                column: "SportCategoryId",
                principalTable: "SportsCategories",
                principalColumn: "Id",
                onDelete: ReferentialAction.Restrict);

            migrationBuilder.AddForeignKey(
                name: "FK_Results_SportsCategories_SportId",
                table: "Results",
                column: "SportId",
                principalTable: "SportsCategories",
                principalColumn: "Id",
                onDelete: ReferentialAction.Restrict);
        }
    }
}
