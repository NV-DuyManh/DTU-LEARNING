/*
 Navicat Premium Data Transfer

 Source Server         : mySQL
 Source Server Type    : MySQL
 Source Server Version : 80041 (8.0.41)
 Source Host           : localhost:3306
 Source Schema         : payroll_2026

 Target Server Type    : MySQL
 Target Server Version : 80041 (8.0.41)
 File Encoding         : 65001

 Date: 14/01/2026 19:02:44
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for attendance
-- ----------------------------
DROP TABLE IF EXISTS `attendance`;
CREATE TABLE `attendance`  (
  `AttendanceID` int NOT NULL AUTO_INCREMENT,
  `EmployeeID` int NULL DEFAULT NULL,
  `WorkDays` int NOT NULL,
  `AbsentDays` int NULL DEFAULT 0,
  `LeaveDays` int NULL DEFAULT 0,
  `AttendanceMonth` date NOT NULL,
  `CreatedAt` datetime NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`AttendanceID`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 21 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of attendance
-- ----------------------------
INSERT INTO `attendance` VALUES (1, 1, 22, 1, 0, '2024-09-01', '2025-10-20 19:13:03');
INSERT INTO `attendance` VALUES (2, 2, 21, 0, 1, '2024-09-01', '2025-10-20 19:13:03');
INSERT INTO `attendance` VALUES (3, 3, 23, 0, 0, '2024-09-01', '2025-10-20 19:13:03');
INSERT INTO `attendance` VALUES (4, 4, 22, 2, 0, '2024-09-01', '2025-10-20 19:13:03');
INSERT INTO `attendance` VALUES (5, 5, 18, 3, 2, '2024-09-01', '2025-10-20 19:13:03');
INSERT INTO `attendance` VALUES (6, 6, 24, 0, 0, '2024-09-01', '2025-10-20 19:13:03');
INSERT INTO `attendance` VALUES (7, 7, 20, 1, 1, '2024-09-01', '2025-10-20 19:13:03');
INSERT INTO `attendance` VALUES (8, 8, 19, 2, 0, '2024-09-01', '2025-10-20 19:13:03');
INSERT INTO `attendance` VALUES (9, 9, 16, 0, 2, '2024-09-01', '2025-10-20 19:13:03');
INSERT INTO `attendance` VALUES (10, 10, 22, 1, 0, '2024-09-01', '2025-10-20 19:13:03');
INSERT INTO `attendance` VALUES (11, 1, 22, 1, 0, '2024-09-01', '2025-10-20 19:14:40');
INSERT INTO `attendance` VALUES (12, 2, 21, 0, 1, '2024-09-01', '2025-10-20 19:14:40');
INSERT INTO `attendance` VALUES (13, 3, 23, 0, 0, '2024-09-01', '2025-10-20 19:14:40');
INSERT INTO `attendance` VALUES (14, 4, 22, 2, 0, '2024-09-01', '2025-10-20 19:14:40');
INSERT INTO `attendance` VALUES (15, 5, 18, 3, 2, '2024-09-01', '2025-10-20 19:14:40');
INSERT INTO `attendance` VALUES (16, 6, 24, 0, 0, '2024-09-01', '2025-10-20 19:14:40');
INSERT INTO `attendance` VALUES (17, 7, 20, 1, 1, '2024-09-01', '2025-10-20 19:14:40');
INSERT INTO `attendance` VALUES (18, 8, 19, 2, 0, '2024-09-01', '2025-10-20 19:14:40');
INSERT INTO `attendance` VALUES (19, 9, 16, 0, 2, '2024-09-01', '2025-10-20 19:14:40');
INSERT INTO `attendance` VALUES (20, 10, 22, 1, 0, '2024-09-01', '2025-10-20 19:14:40');

-- ----------------------------
-- Table structure for departments_payroll
-- ----------------------------
DROP TABLE IF EXISTS `departments_payroll`;
CREATE TABLE `departments_payroll`  (
  `DepartmentID` int NOT NULL,
  `DepartmentName` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `SyncedAt` datetime NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`DepartmentID`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of departments_payroll
-- ----------------------------
INSERT INTO `departments_payroll` VALUES (1, 'Phòng Nhân sự', '2025-10-20 19:13:03');
INSERT INTO `departments_payroll` VALUES (2, 'Phòng Kế toán', '2025-10-20 19:13:03');
INSERT INTO `departments_payroll` VALUES (3, 'Phòng Kỹ thuật', '2025-10-20 19:13:03');
INSERT INTO `departments_payroll` VALUES (4, 'Phòng Kinh doanh', '2025-10-20 19:13:03');
INSERT INTO `departments_payroll` VALUES (5, 'Phòng Hành chính', '2025-10-20 19:13:03');
INSERT INTO `departments_payroll` VALUES (6, 'Phòng Marketing', '2025-10-20 19:13:03');
INSERT INTO `departments_payroll` VALUES (7, 'Phòng Sản xuất', '2025-10-20 19:13:03');
INSERT INTO `departments_payroll` VALUES (8, 'Phòng Bảo trì', '2025-10-20 19:13:03');
INSERT INTO `departments_payroll` VALUES (9, 'Phòng Nghiên cứu & Phát triển', '2025-10-20 19:13:03');
INSERT INTO `departments_payroll` VALUES (10, 'Phòng Dịch vụ khách hàng', '2025-10-20 19:13:03');

-- ----------------------------
-- Table structure for employees_payroll
-- ----------------------------
DROP TABLE IF EXISTS `employees_payroll`;
CREATE TABLE `employees_payroll`  (
  `EmployeeID` int NOT NULL,
  `FullName` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `DepartmentID` int NULL DEFAULT NULL,
  `PositionID` int NULL DEFAULT NULL,
  `Status` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `SyncedAt` datetime NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`EmployeeID`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of employees_payroll
-- ----------------------------
INSERT INTO `employees_payroll` VALUES (1, 'Nguyễn Văn An', 1, 1, 'Đang làm việc', '2025-10-20 19:13:03');
INSERT INTO `employees_payroll` VALUES (2, 'Lê Thị Bình', 2, 3, 'Đang làm việc', '2025-10-20 19:13:03');
INSERT INTO `employees_payroll` VALUES (3, 'Trần Quốc Cường', 3, 7, 'Đang làm việc', '2025-10-20 19:13:03');
INSERT INTO `employees_payroll` VALUES (4, 'Phạm Hồng Dung', 4, 2, 'Đang làm việc', '2025-10-20 19:13:03');
INSERT INTO `employees_payroll` VALUES (5, 'Võ Thành Đạt', 5, 4, 'Nghỉ phép', '2025-10-20 19:13:03');
INSERT INTO `employees_payroll` VALUES (6, 'Đặng Minh Hạnh', 6, 1, 'Đang làm việc', '2025-10-20 19:13:03');
INSERT INTO `employees_payroll` VALUES (7, 'Lưu Trung Hiếu', 7, 5, 'Đang làm việc', '2025-10-20 19:13:03');
INSERT INTO `employees_payroll` VALUES (8, 'Ngô Thu Lan', 8, 8, 'Thử việc', '2025-10-20 19:13:03');
INSERT INTO `employees_payroll` VALUES (9, 'Bùi Văn Minh', 9, 9, 'Thực tập', '2025-10-20 19:13:03');
INSERT INTO `employees_payroll` VALUES (10, 'Hoàng Thị Oanh', 10, 6, 'Đang làm việc', '2025-10-20 19:13:03');

-- ----------------------------
-- Table structure for positions_payroll
-- ----------------------------
DROP TABLE IF EXISTS `positions_payroll`;
CREATE TABLE `positions_payroll`  (
  `PositionID` int NOT NULL,
  `PositionName` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `SyncedAt` datetime NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`PositionID`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of positions_payroll
-- ----------------------------
INSERT INTO `positions_payroll` VALUES (1, 'Nhân viên', '2025-10-20 19:13:03');
INSERT INTO `positions_payroll` VALUES (2, 'Trưởng nhóm', '2025-10-20 19:13:03');
INSERT INTO `positions_payroll` VALUES (3, 'Phó phòng', '2025-10-20 19:13:03');
INSERT INTO `positions_payroll` VALUES (4, 'Trưởng phòng', '2025-10-20 19:13:03');
INSERT INTO `positions_payroll` VALUES (5, 'Giám đốc', '2025-10-20 19:13:03');
INSERT INTO `positions_payroll` VALUES (6, 'Thư ký', '2025-10-20 19:13:03');
INSERT INTO `positions_payroll` VALUES (7, 'Kỹ sư', '2025-10-20 19:13:03');
INSERT INTO `positions_payroll` VALUES (8, 'Nhân viên thử việc', '2025-10-20 19:13:03');
INSERT INTO `positions_payroll` VALUES (9, 'Thực tập sinh', '2025-10-20 19:13:03');
INSERT INTO `positions_payroll` VALUES (10, 'Cố vấn kỹ thuật', '2025-10-20 19:13:03');

-- ----------------------------
-- Table structure for salaries
-- ----------------------------
DROP TABLE IF EXISTS `salaries`;
CREATE TABLE `salaries`  (
  `SalaryID` int NOT NULL AUTO_INCREMENT,
  `EmployeeID` int NULL DEFAULT NULL,
  `SalaryMonth` date NOT NULL,
  `BaseSalary` decimal(12, 2) NOT NULL,
  `Bonus` decimal(12, 2) NULL DEFAULT 0.00,
  `Deductions` decimal(12, 2) NULL DEFAULT 0.00,
  `NetSalary` decimal(12, 2) NOT NULL,
  `CreatedAt` datetime NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`SalaryID`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 21 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of salaries
-- ----------------------------
INSERT INTO `salaries` VALUES (1, 1, '2024-09-01', 12000000.00, 500000.00, 200000.00, 12300000.00, '2025-10-20 19:13:03');
INSERT INTO `salaries` VALUES (2, 2, '2024-09-01', 10000000.00, 800000.00, 100000.00, 10700000.00, '2025-10-20 19:13:03');
INSERT INTO `salaries` VALUES (3, 3, '2024-09-01', 15000000.00, 600000.00, 0.00, 15600000.00, '2025-10-20 19:13:03');
INSERT INTO `salaries` VALUES (4, 4, '2024-09-01', 11000000.00, 400000.00, 100000.00, 11300000.00, '2025-10-20 19:13:03');
INSERT INTO `salaries` VALUES (5, 5, '2024-09-01', 9000000.00, 0.00, 300000.00, 8700000.00, '2025-10-20 19:13:03');
INSERT INTO `salaries` VALUES (6, 6, '2024-09-01', 9500000.00, 500000.00, 0.00, 10000000.00, '2025-10-20 19:13:03');
INSERT INTO `salaries` VALUES (7, 7, '2024-09-01', 18000000.00, 1000000.00, 0.00, 19000000.00, '2025-10-20 19:13:03');
INSERT INTO `salaries` VALUES (8, 8, '2024-09-01', 7000000.00, 200000.00, 0.00, 7200000.00, '2025-10-20 19:13:03');
INSERT INTO `salaries` VALUES (9, 9, '2024-09-01', 5000000.00, 0.00, 0.00, 5000000.00, '2025-10-20 19:13:03');
INSERT INTO `salaries` VALUES (10, 10, '2024-09-01', 8500000.00, 300000.00, 100000.00, 8700000.00, '2025-10-20 19:13:03');
INSERT INTO `salaries` VALUES (11, 1, '2024-09-01', 12000000.00, 500000.00, 200000.00, 12300000.00, '2025-10-20 19:15:00');
INSERT INTO `salaries` VALUES (12, 2, '2024-09-01', 10000000.00, 800000.00, 100000.00, 10700000.00, '2025-10-20 19:15:00');
INSERT INTO `salaries` VALUES (13, 3, '2024-09-01', 15000000.00, 600000.00, 0.00, 15600000.00, '2025-10-20 19:15:00');
INSERT INTO `salaries` VALUES (14, 4, '2024-09-01', 11000000.00, 400000.00, 100000.00, 11300000.00, '2025-10-20 19:15:00');
INSERT INTO `salaries` VALUES (15, 5, '2024-09-01', 9000000.00, 0.00, 300000.00, 8700000.00, '2025-10-20 19:15:00');
INSERT INTO `salaries` VALUES (16, 6, '2024-09-01', 9500000.00, 500000.00, 0.00, 10000000.00, '2025-10-20 19:15:00');
INSERT INTO `salaries` VALUES (17, 7, '2024-09-01', 18000000.00, 1000000.00, 0.00, 19000000.00, '2025-10-20 19:15:00');
INSERT INTO `salaries` VALUES (18, 8, '2024-09-01', 7000000.00, 200000.00, 0.00, 7200000.00, '2025-10-20 19:15:00');
INSERT INTO `salaries` VALUES (19, 9, '2024-09-01', 5000000.00, 0.00, 0.00, 5000000.00, '2025-10-20 19:15:00');
INSERT INTO `salaries` VALUES (20, 10, '2024-09-01', 8500000.00, 300000.00, 100000.00, 8700000.00, '2025-10-20 19:15:00');

SET FOREIGN_KEY_CHECKS = 1;
