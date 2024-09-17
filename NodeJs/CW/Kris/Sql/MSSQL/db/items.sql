USE [testdb]
GO

SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO

CREATE TABLE [dbo].[items]
(
	[id] [int] IDENTITY(1,1) NOT NULL,
	[description] [nvarchar](50) NULL
)
