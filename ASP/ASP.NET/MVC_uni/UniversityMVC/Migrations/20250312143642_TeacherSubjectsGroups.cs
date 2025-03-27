using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace UniversityMVC.Migrations
{
    /// <inheritdoc />
    public partial class TeacherSubjectsGroups : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_Teachers_SubjectsGroups_SubjectsGroupsId",
                table: "Teachers");

            migrationBuilder.DropIndex(
                name: "IX_Teachers_SubjectsGroupsId",
                table: "Teachers");

            migrationBuilder.DropColumn(
                name: "SubjectsGroupsId",
                table: "Teachers");

            migrationBuilder.AddColumn<int>(
                name: "TeacherId",
                table: "SubjectsGroups",
                type: "int",
                nullable: true);

            migrationBuilder.CreateTable(
                name: "TeacherSubjectsGroups",
                columns: table => new
                {
                    Id = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    TeacherId = table.Column<int>(type: "int", nullable: false),
                    SubjectsGroupsId = table.Column<int>(type: "int", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_TeacherSubjectsGroups", x => x.Id);
                    table.ForeignKey(
                        name: "FK_TeacherSubjectsGroups_SubjectsGroups_SubjectsGroupsId",
                        column: x => x.SubjectsGroupsId,
                        principalTable: "SubjectsGroups",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                    table.ForeignKey(
                        name: "FK_TeacherSubjectsGroups_Teachers_TeacherId",
                        column: x => x.TeacherId,
                        principalTable: "Teachers",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateIndex(
                name: "IX_SubjectsGroups_TeacherId",
                table: "SubjectsGroups",
                column: "TeacherId");

            migrationBuilder.CreateIndex(
                name: "IX_TeacherSubjectsGroups_SubjectsGroupsId",
                table: "TeacherSubjectsGroups",
                column: "SubjectsGroupsId");

            migrationBuilder.CreateIndex(
                name: "IX_TeacherSubjectsGroups_TeacherId",
                table: "TeacherSubjectsGroups",
                column: "TeacherId");

            migrationBuilder.AddForeignKey(
                name: "FK_SubjectsGroups_Teachers_TeacherId",
                table: "SubjectsGroups",
                column: "TeacherId",
                principalTable: "Teachers",
                principalColumn: "Id");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_SubjectsGroups_Teachers_TeacherId",
                table: "SubjectsGroups");

            migrationBuilder.DropTable(
                name: "TeacherSubjectsGroups");

            migrationBuilder.DropIndex(
                name: "IX_SubjectsGroups_TeacherId",
                table: "SubjectsGroups");

            migrationBuilder.DropColumn(
                name: "TeacherId",
                table: "SubjectsGroups");

            migrationBuilder.AddColumn<int>(
                name: "SubjectsGroupsId",
                table: "Teachers",
                type: "int",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.CreateIndex(
                name: "IX_Teachers_SubjectsGroupsId",
                table: "Teachers",
                column: "SubjectsGroupsId");

            migrationBuilder.AddForeignKey(
                name: "FK_Teachers_SubjectsGroups_SubjectsGroupsId",
                table: "Teachers",
                column: "SubjectsGroupsId",
                principalTable: "SubjectsGroups",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);
        }
    }
}
