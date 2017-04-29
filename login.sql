use mpicl; 
DROP TABLE IF EXISTS user; 
DROP TABLE IF EXISTS auth_info;
DROP TABLE IF EXISTS auth_token;

create table user (
  id int primary key auto_increment,
  version int not null
);

create table auth_info (
  id int primary key auto_increment,
  version int not null,
  user_id int,
  password_hash  varchar(100) not null,
  password_method varchar(20) not null,
  password_salt varchar(20) not null,
  status int not null,
  failed_login_attempts int not null,
  last_login_attempt text,
  email varchar(256) not null,
  unverified_email varchar(256) not null,
  email_token varchar(64) not null,
  email_token_expires text,
  email_token_role integer not null,
  foreign key  (user_id) references user(id)
  ON DELETE CASCADE ON UPDATE CASCADE 
);

create table auth_token (
  id integer primary key auto_increment,
  version int not null,
  auth_info_id int,
  value varchar(64) not null,
  expires text,
  foreign key  (auth_info_id) references auth_info(id)
  ON DELETE CASCADE ON UPDATE CASCADE 
);

create table auth_identity (
  id int primary key auto_increment,
  version int not null,
  auth_info_id int,
  provider varchar(64) not null,
  identity varchar(512) not null,
  foreign key (auth_info_id) references auth_info(id)
  ON DELETE CASCADE ON UPDATE CASCADE 
);
