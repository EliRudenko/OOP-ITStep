using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace UniversityMVC.Migrations
{
    /// <inheritdoc />
    public partial class ManualSubjectsGroups : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_SubjectsGroups_Groups_GroupsId",
                table: "SubjectsGroups");

            migrationBuilder.DropForeignKey(
                name: "FK_SubjectsGroups_Subjects_SubjectsId",
                table: "SubjectsGroups");

            migrationBuilder.DropPrimaryKey(
                name: "PK_SubjectsGroups",
                table: "SubjectsGroups");

            migrationBuilder.RenameColumn(
                name: "SubjectsId",
                table: "SubjectsGroups",
                newName: "SubjectId");

            migrationBuilder.RenameColumn(
                name: "GroupsId",
                table: "SubjectsGroups",
                newName: "GroupId");

            migrationBuilder.RenameIndex(
                name: "IX_SubjectsGroups_SubjectsId",
                table: "SubjectsGroups",
                newName: "IX_SubjectsGroups_SubjectId");

            migrationBuilder.AddColumn<int>(
                name: "SubjectsGroupsId",
                table: "Teachers",
                type: "int",
                nullable: false,
                defaultValue: 0);

            migrationBuilder.AddColumn<int>(
                name: "Id",
                table: "SubjectsGroups",
                type: "int",
                nullable: false,
                defaultValue: 0)
                .Annotation("SqlServer:Identity", "1, 1");

            migrationBuilder.AddPrimaryKey(
                name: "PK_SubjectsGroups",
                table: "SubjectsGroups",
                column: "Id");

            migrationBuilder.CreateIndex(
                name: "IX_Teachers_SubjectsGroupsId",
                table: "Teachers",
                column: "SubjectsGroupsId");

            migrationBuilder.CreateIndex(
                name: "IX_SubjectsGroups_GroupId",
                table: "SubjectsGroups",
                column: "GroupId");

            migrationBuilder.AddForeignKey(
                name: "FK_SubjectsGroups_Groups_GroupId",
                table: "SubjectsGroups",
                column: "GroupId",
                principalTable: "Groups",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);

            migrationBuilder.AddForeignKey(
                name: "FK_SubjectsGroups_Subjects_SubjectId",
                table: "SubjectsGroups",
                column: "SubjectId",
                principalTable: "Subjects",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);

            migrationBuilder.AddForeignKey(
                name: "FK_Teachers_SubjectsGroups_SubjectsGroupsId",
                table: "Teachers",
                column: "SubjectsGroupsId",
                principalTable: "SubjectsGroups",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_SubjectsGroups_Groups_GroupId",
                table: "SubjectsGroups");

            migrationBuilder.DropForeignKey(
                name: "FK_SubjectsGroups_Subjects_SubjectId",
                table: "SubjectsGroups");

            migrationBuilder.DropForeignKey(
                name: "FK_Teachers_SubjectsGroups_SubjectsGroupsId",
                table: "Teachers");

            migrationBuilder.DropIndex(
                name: "IX_Teachers_SubjectsGroupsId",
                table: "Teachers");

            migrationBuilder.DropPrimaryKey(
                name: "PK_SubjectsGroups",
                table: "SubjectsGroups");

            migrationBuilder.DropIndex(
                name: "IX_SubjectsGroups_GroupId",
                table: "SubjectsGroups");

            migrationBuilder.DropColumn(
                name: "SubjectsGroupsId",
                table: "Teachers");

            migrationBuilder.DropColumn(
                name: "Id",
                table: "SubjectsGroups");

            migrationBuilder.RenameColumn(
                name: "SubjectId",
                table: "SubjectsGroups",
                newName: "SubjectsId");

            migrationBuilder.RenameColumn(
                name: "GroupId",
                table: "SubjectsGroups",
                newName: "GroupsId");

            migrationBuilder.RenameIndex(
                name: "IX_SubjectsGroups_SubjectId",
                table: "SubjectsGroups",
                newName: "IX_SubjectsGroups_SubjectsId");

            migrationBuilder.AddPrimaryKey(
                name: "PK_SubjectsGroups",
                table: "SubjectsGroups",
                columns: new[] { "GroupsId", "SubjectsId" });

            migrationBuilder.AddForeignKey(
                name: "FK_SubjectsGroups_Groups_GroupsId",
                table: "SubjectsGroups",
                column: "GroupsId",
                principalTable: "Groups",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);

            migrationBuilder.AddForeignKey(
                name: "FK_SubjectsGroups_Subjects_SubjectsId",
                table: "SubjectsGroups",
                column: "SubjectsId",
                principalTable: "Subjects",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);
        }
    }
}
