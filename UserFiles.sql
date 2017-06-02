use mpicl;

INSERT INTO Users(user, password) VALUES("Nick Cerminara", "password");
INSERT INTO Users(user, password) VALUES("User", "pwd");

INSERT INTO Files(filename) VALUES("trace1");
INSERT INTO Files(filename) VALUES("trace2");
INSERT INTO Files(filename) VALUES("trace3");

INSERT INTO FilesUsers(user, filename) VALUES("Nick Cerminara", "trace1");
INSERT INTO FilesUsers(user, filename) VALUES("Nick Cerminara", "trace2");
INSERT INTO FilesUsers(user, filename) VALUES("Nick Cerminara", "trace3");
INSERT INTO FilesUsers(user, filename) VALUES("User", "trace1");
INSERT INTO FilesUsers(user, filename) VALUES("User", "trace2");
