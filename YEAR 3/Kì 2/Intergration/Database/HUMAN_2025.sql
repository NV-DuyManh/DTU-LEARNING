CREATE DATABASE HUMAN_2025;
GO

USE HUMAN_2025;
GO


-- =========================
-- TABLE: Departments
-- =========================

CREATE TABLE Departments (
    DepartmentID INT IDENTITY(1,1) PRIMARY KEY,
    DepartmentName NVARCHAR(100) NOT NULL,
    CreatedAt DATETIME DEFAULT GETDATE(),
    UpdatedAt DATETIME DEFAULT GETDATE()
);

SET IDENTITY_INSERT Departments ON;

INSERT INTO Departments VALUES
(1,N'Phòng Nhân sự',GETDATE(),GETDATE()),
(2,N'Phòng Kế toán',GETDATE(),GETDATE()),
(3,N'Phòng Kỹ thuật',GETDATE(),GETDATE()),
(4,N'Phòng Kinh doanh',GETDATE(),GETDATE()),
(5,N'Phòng Hành chính',GETDATE(),GETDATE()),
(6,N'Phòng Marketing',GETDATE(),GETDATE()),
(7,N'Phòng Sản xuất',GETDATE(),GETDATE()),
(8,N'Phòng Bảo trì',GETDATE(),GETDATE()),
(9,N'Phòng Nghiên cứu & Phát triển',GETDATE(),GETDATE()),
(10,N'Phòng Dịch vụ khách hàng',GETDATE(),GETDATE());

SET IDENTITY_INSERT Departments OFF;



-- =========================
-- TABLE: Positions
-- =========================

CREATE TABLE Positions(
    PositionID INT IDENTITY(1,1) PRIMARY KEY,
    PositionName NVARCHAR(100) NOT NULL,
    CreatedAt DATETIME DEFAULT GETDATE(),
    UpdatedAt DATETIME DEFAULT GETDATE()
);

SET IDENTITY_INSERT Positions ON;

INSERT INTO Positions VALUES
(1,N'Nhân viên',GETDATE(),GETDATE()),
(2,N'Trưởng nhóm',GETDATE(),GETDATE()),
(3,N'Phó phòng',GETDATE(),GETDATE()),
(4,N'Trưởng phòng',GETDATE(),GETDATE()),
(5,N'Giám đốc',GETDATE(),GETDATE()),
(6,N'Thư ký',GETDATE(),GETDATE()),
(7,N'Kỹ sư',GETDATE(),GETDATE()),
(8,N'Nhân viên thử việc',GETDATE(),GETDATE()),
(9,N'Thực tập sinh',GETDATE(),GETDATE()),
(10,N'Cố vấn kỹ thuật',GETDATE(),GETDATE());

SET IDENTITY_INSERT Positions OFF;



-- =========================
-- TABLE: Employees
-- =========================

CREATE TABLE Employees(
    EmployeeID INT IDENTITY(1,1) PRIMARY KEY,
    FullName NVARCHAR(100) NOT NULL,
    DateOfBirth DATE NOT NULL,
    Gender NVARCHAR(10),
    PhoneNumber NVARCHAR(15),
    Email NVARCHAR(100) UNIQUE,
    HireDate DATE NOT NULL,

    DepartmentID INT,
    PositionID INT,

    Status NVARCHAR(50),

    CreatedAt DATETIME DEFAULT GETDATE(),
    UpdatedAt DATETIME DEFAULT GETDATE(),

    FOREIGN KEY (DepartmentID)
        REFERENCES Departments(DepartmentID),

    FOREIGN KEY (PositionID)
        REFERENCES Positions(PositionID)
);

SET IDENTITY_INSERT Employees ON;

INSERT INTO Employees VALUES
(1,N'Nguyễn Văn An','1990-02-15',N'Nam','0901234567','an.nguyen@company.vn','2020-01-10',1,1,N'Đang làm việc',GETDATE(),GETDATE()),
(2,N'Lê Thị Bình','1992-05-22',N'Nữ','0912345678','binh.le@company.vn','2019-03-12',2,3,N'Đang làm việc',GETDATE(),GETDATE()),
(3,N'Trần Quốc Cường','1988-11-10',N'Nam','0987654321','cuong.tran@company.vn','2021-05-05',3,7,N'Đang làm việc',GETDATE(),GETDATE()),
(4,N'Phạm Hồng Dung','1995-06-08',N'Nữ','0934567890','dung.pham@company.vn','2022-02-01',4,2,N'Đang làm việc',GETDATE(),GETDATE()),
(5,N'Võ Thành Đạt','1991-09-19',N'Nam','0945678901','dat.vo@company.vn','2018-07-20',5,4,N'Nghỉ phép',GETDATE(),GETDATE()),
(6,N'Đặng Minh Hạnh','1996-04-25',N'Nữ','0976543210','hanh.dang@company.vn','2023-01-01',6,1,N'Đang làm việc',GETDATE(),GETDATE()),
(7,N'Lưu Trung Hiếu','1993-03-30',N'Nam','0956789012','hieu.luu@company.vn','2017-09-15',7,5,N'Đang làm việc',GETDATE(),GETDATE()),
(8,N'Ngô Thu Lan','1998-12-12',N'Nữ','0901122334','lan.ngo@company.vn','2024-03-03',8,8,N'Thử việc',GETDATE(),GETDATE()),
(9,N'Bùi Văn Minh','1989-10-05',N'Nam','0933111222','minh.bui@company.vn','2016-11-11',9,9,N'Thực tập',GETDATE(),GETDATE()),
(10,N'Hoàng Thị Oanh','1994-07-17',N'Nữ','0909988776','oanh.hoang@company.vn','2020-06-01',10,6,N'Đang làm việc',GETDATE(),GETDATE());

SET IDENTITY_INSERT Employees OFF;



-- =========================
-- TABLE: Dividends
-- =========================

CREATE TABLE Dividends(
    DividendID INT IDENTITY(1,1) PRIMARY KEY,
    EmployeeID INT,
    DividendAmount DECIMAL(12,2) NOT NULL,
    DividendDate DATE NOT NULL,
    CreatedAt DATETIME DEFAULT GETDATE(),

    FOREIGN KEY (EmployeeID)
        REFERENCES Employees(EmployeeID)
);

SET IDENTITY_INSERT Dividends ON;

INSERT INTO Dividends VALUES
(1,1,500000,'2024-12-31',GETDATE()),
(2,2,800000,'2024-12-31',GETDATE()),
(3,3,300000,'2024-12-31',GETDATE()),
(4,4,700000,'2024-12-31',GETDATE()),
(5,5,400000,'2024-12-31',GETDATE()),
(6,6,600000,'2024-12-31',GETDATE()),
(7,7,900000,'2024-12-31',GETDATE()),
(8,8,200000,'2024-12-31',GETDATE()),
(9,9,150000,'2024-12-31',GETDATE()),
(10,10,850000,'2024-12-31',GETDATE());

SET IDENTITY_INSERT Dividends OFF;



-- =========================
-- TEST
-- =========================

SELECT * FROM Departments;
SELECT * FROM Positions;
SELECT * FROM Employees;
SELECT * FROM Dividends;