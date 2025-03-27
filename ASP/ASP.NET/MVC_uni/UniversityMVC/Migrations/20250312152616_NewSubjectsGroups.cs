using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace UniversityMVC.Migrations
{
    /// <inheritdoc />
    public partial class NewSubjectsGroups : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_SubjectsGroups_Teachers_TeacherId",
                table: "SubjectsGroups");

            migrationBuilder.DropTable(
                name: "TeacherSubjectsGroups");

            migrationBuilder.AlterColumn<int>(
                name: "TeacherId",
                table: "SubjectsGroups",
                type: "int",
                nullable: false,
                defaultValue: 0,
                oldClrType: typeof(int),
                oldType: "int",
                oldNullable: true);

            migrationBuilder.CreateTable(
                name: "GroupSubject",
                columns: table => new
                {
                    GroupsId = table.Column<int>(type: "int", nullable: false),
                    SubjectsId = table.Column<int>(type: "int", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_GroupSubject", x => new { x.GroupsId, x.SubjectsId });
                    table.ForeignKey(
                        name: "FK_GroupSubject_Groups_GroupsId",
                        column: x => x.GroupsId,
                        principalTable: "Groups",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                    table.ForeignKey(
                        name: "FK_GroupSubject_Subjects_SubjectsId",
                        column: x => x.SubjectsId,
                        principalTable: "Subjects",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.CreateIndex(
                name: "IX_GroupSubject_SubjectsId",
                table: "GroupSubject",
                column: "SubjectsId");

            migrationBuilder.AddForeignKey(
                name: "FK_SubjectsGroups_Teachers_TeacherId",
                table: "SubjectsGroups",
                column: "TeacherId",
                principalTable: "Teachers",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_SubjectsGroups_Teachers_TeacherId",
                table: "SubjectsGroups");

            migrationBuilder.DropTable(
                name: "GroupSubject");

            migrationBuilder.AlterColumn<int>(
                name: "TeacherId",
                table: "SubjectsGroups",
                type: "int",
                nullable: true,
                oldClrType: typeof(int),
                oldType: "int");

            migrationBuilder.CreateTable(
                name: "TeacherSubjectsGroups",
                columns: table => new
                {
                    Id = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    SubjectsGroupsId = table.Column<int>(type: "int", nullable: false),
                    TeacherId = table.Column<int>(type: "int", nullable: false)
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
    }
}
