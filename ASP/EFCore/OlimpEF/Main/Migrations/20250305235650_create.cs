using System;
using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace Main.Migrations
{
    /// <inheritdoc />
    public partial class create : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "Countries",
                columns: table => new
                {
                    Id = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    Name = table.Column<string>(type: "nvarchar(100)", maxLength: 100, nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Countries", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "Sports",
                columns: table => new
                {
                    Id = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    Name = table.Column<string>(type: "nvarchar(100)", maxLength: 100, nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Sports", x => x.Id);
                    table.CheckConstraint("CK_Sport_Name", "LEN(Name)>0");
                });

            migrationBuilder.CreateTable(
                name: "Cities",
                columns: table => new
                {
                    Id = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    Name = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    CountryId = table.Column<int>(type: "int", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Cities", x => x.Id);
                    table.ForeignKey(
                        name: "FK_Cities_Countries_CountryId",
                        column: x => x.CountryId,
                        principalTable: "Countries",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateTable(
                name: "Olympiads",
                columns: table => new
                {
                    Id = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    Year = table.Column<int>(type: "int", nullable: false),
                    Season = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    CityId = table.Column<int>(type: "int", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Olympiads", x => x.Id);
                    table.CheckConstraint("CK_Olympiad_Leap_Year", "Year % 4 = 0");
                    table.CheckConstraint("CK_Olympiad_Season", "Season = 'Summer' OR Season = 'Winter'");
                    table.CheckConstraint("CK_Olympiad_Year", "Year>=1896 AND Year<=2024");
                    table.ForeignKey(
                        name: "FK_Olympiads_Cities_CityId",
                        column: x => x.CityId,
                        principalTable: "Cities",
                        principalColumn: "Id");
                });

            migrationBuilder.CreateTable(
                name: "SportsCategories",
                columns: table => new
                {
                    Id = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    SportId = table.Column<int>(type: "int", nullable: false),
                    ParticipantsCount = table.Column<int>(type: "int", nullable: false),
                    OlympiadId = table.Column<int>(type: "int", nullable: false)
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

            migrationBuilder.CreateTable(
                name: "Participants",
                columns: table => new
                {
                    Id = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    Name = table.Column<string>(type: "nvarchar(100)", maxLength: 100, nullable: false),
                    Surname = table.Column<string>(type: "nvarchar(100)", maxLength: 100, nullable: false),
                    Birthday = table.Column<DateOnly>(type: "date", nullable: false),
                    CityId = table.Column<int>(type: "int", nullable: false),
                    SportId = table.Column<int>(type: "int", nullable: false),
                    OlympiadId = table.Column<int>(type: "int", nullable: false),
                    SportCategoryId = table.Column<int>(type: "int", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Participants", x => x.Id);
                    table.CheckConstraint("CK_Participant_Name", "LEN(Name)>0");
                    table.CheckConstraint("CK_Participant_Surname", "LEN(Surname)>0");
                    table.ForeignKey(
                        name: "FK_Participants_Cities_CityId",
                        column: x => x.CityId,
                        principalTable: "Cities",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Restrict);
                    table.ForeignKey(
                        name: "FK_Participants_Olympiads_OlympiadId",
                        column: x => x.OlympiadId,
                        principalTable: "Olympiads",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                    table.ForeignKey(
                        name: "FK_Participants_SportsCategories_SportCategoryId",
                        column: x => x.SportCategoryId,
                        principalTable: "SportsCategories",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Restrict);
                    table.ForeignKey(
                        name: "FK_Participants_Sports_SportId",
                        column: x => x.SportId,
                        principalTable: "Sports",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Restrict);
                });

            migrationBuilder.CreateTable(
                name: "Results",
                columns: table => new
                {
                    Id = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    Place = table.Column<int>(type: "int", nullable: false),
                    ParticipantId = table.Column<int>(type: "int", nullable: false),
                    SportId = table.Column<int>(type: "int", nullable: false),
                    OlympiadId = table.Column<int>(type: "int", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Results", x => x.Id);
                    table.CheckConstraint("CK_Result_Place", "Place>0 AND Place<=64");
                    table.ForeignKey(
                        name: "FK_Results_Olympiads_OlympiadId",
                        column: x => x.OlympiadId,
                        principalTable: "Olympiads",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                    table.ForeignKey(
                        name: "FK_Results_Participants_ParticipantId",
                        column: x => x.ParticipantId,
                        principalTable: "Participants",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Restrict);
                    table.ForeignKey(
                        name: "FK_Results_SportsCategories_SportId",
                        column: x => x.SportId,
                        principalTable: "SportsCategories",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Restrict);
                });

            migrationBuilder.CreateIndex(
                name: "IX_Cities_CountryId",
                table: "Cities",
                column: "CountryId");

            migrationBuilder.CreateIndex(
                name: "IX_Countries_Name",
                table: "Countries",
                column: "Name",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_Olympiads_CityId",
                table: "Olympiads",
                column: "CityId");

            migrationBuilder.CreateIndex(
                name: "IX_Participants_CityId",
                table: "Participants",
                column: "CityId");

            migrationBuilder.CreateIndex(
                name: "IX_Participants_OlympiadId",
                table: "Participants",
                column: "OlympiadId");

            migrationBuilder.CreateIndex(
                name: "IX_Participants_SportCategoryId",
                table: "Participants",
                column: "SportCategoryId");

            migrationBuilder.CreateIndex(
                name: "IX_Participants_SportId",
                table: "Participants",
                column: "SportId");

            migrationBuilder.CreateIndex(
                name: "IX_Results_OlympiadId",
                table: "Results",
                column: "OlympiadId");

            migrationBuilder.CreateIndex(
                name: "IX_Results_ParticipantId",
                table: "Results",
                column: "ParticipantId",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_Results_SportId",
                table: "Results",
                column: "SportId");

            migrationBuilder.CreateIndex(
                name: "IX_Sports_Name",
                table: "Sports",
                column: "Name",
                unique: true);

            migrationBuilder.CreateIndex(
                name: "IX_SportsCategories_OlympiadId",
                table: "SportsCategories",
                column: "OlympiadId");

            migrationBuilder.CreateIndex(
                name: "IX_SportsCategories_SportId",
                table: "SportsCategories",
                column: "SportId",
                unique: true);
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "Results");

            migrationBuilder.DropTable(
                name: "Participants");

            migrationBuilder.DropTable(
                name: "SportsCategories");

            migrationBuilder.DropTable(
                name: "Olympiads");

            migrationBuilder.DropTable(
                name: "Sports");

            migrationBuilder.DropTable(
                name: "Cities");

            migrationBuilder.DropTable(
                name: "Countries");
        }
    }
}
