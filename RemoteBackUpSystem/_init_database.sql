-- 创建数据库 
create database BACKUP;

-- 使用数据库
use BACKUP;

-- 创建lib表 
create table lib(
	id int primary key auto_increment,
    lib_name varchar(20) not null unique key,
    lib_addr varchar(15) not null,
    lib_port int not null,
    lib_user int not null
);

-- 创建user表
create table user(
	id int primary key auto_increment,
    user_name varchar(255) not null unique key,
    user_pswd varchar(255) not null
); 

-- 创建plane表
create table plane(
	id int primary key auto_increment,
    plane_libid  int not null,
    plane_userid int not null,
    plane_name   varchar(255) not null unique key,
    plane_path   text not null,
    plane_ways   enum('interal','clock') not null,
    plane_interal_time int not null,
    plane_clock_date   int not null,
    plane_clock_time   int not null
);

-- 创建file表
create table file(
	id int primary key auto_increment,
    file_name  varchar(255) not null,
    file_path  varchar(255) not null,
    file_type  varchar(255) not null ,
    file_size  int not null,
    file_date  datetime not null,
    file_user  int not null,
	file_lib   int not null,
    file_plane int not null
); 