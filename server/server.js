// =======================
// get the packages we need ============
// =======================
var express = require('express');
var app = express();
var bodyParser = require('body-parser');
var morgan = require('morgan');
var mongoose = require('mongoose');

var jwt = require('jsonwebtoken'); // used to create, sign, and verify tokens
var config = require('./config'); // get our config file
var User = require('./app/models/user'); // get our mongoose model
var mysql = require('mysql');

var connection = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: '1111',
    database: 'mpicl'
});
// =======================
// configuration =========
// =======================
connection.connect(function (err) {
    if (!err) {
        console.log("Mysql Database is connected ... nn");
    } else {
        console.log("Error connecting database ... nn");
    }
});

var port = process.env.PORT || 8080; // used to create, sign, and verify tokens
mongoose.connect(config.database); // connect to database
app.set('superSecret', config.secret); // secret variable

// use body parser so we can get info from POST and/or URL parameters
app.use(bodyParser.urlencoded({extended: false}));
app.use(bodyParser.json());

// use morgan to log requests to the console
app.use(morgan('dev'));


// =======================
// start the server ======
// =======================
var apiRoutes = express.Router();

app.listen(port);
console.log('Magic happens at http://localhost:' + port);

app.get('/setup', function (req, res) {

    // create a sample user
    let nick = new User({
        name: 'Nick Cerminara',
        password: 'password',
        files: []
    });
    nick.files.push("trace1");
    nick.files.push("trace2");
    nick.files.push("trace3");
    // save the sample user
    nick.save(function (err) {
        if (err) throw err;

        console.log('User saved successfully');
        res.json({success: true});
    });
    let myUser = new User({
        name: 'User',
        password: 'password',
        files: []
    });

    myUser.files.push("trace2");
    myUser.files.push("trace3");
    // save the sample user
});

apiRoutes.get('/', function (req, res) {

    res.json({message: 'Welcome to the coolest API on earth!'});
});


apiRoutes.get('/authenticate', function (req, res) {
    console.log("gg");
    // find the user
    User.findOne({
        name: req.query.name
    }, function (err, user) {

        if (err) throw err;

        if (!user) {
            console.log(req.query.name);
            res.json({success: false, message: 'Authentication failed. User not found.'});
        } else if (user) {

            // check if password matches
            if (user.password != req.query.password) {
                res.json({success: false, message: 'Authentication failed. Wrong password.'});
            } else {

                // if user is found and password is right
                // create a token
                var token = jwt.sign(user, app.get('superSecret'), {
                    expiresIn: 60 * 60 * 24 // expires in 24 hours
                });

                // return the information including token as JSON
                res.json({
                    success: true,
                    message: 'Enjoy your token!',
                    token: token
                });
            }

        }

    });
});


apiRoutes.get("/getFile", function (req, res) {
    let filename = req.query.filename;
    let offset = parseInt(req.query.offset);
    let limit = parseInt(req.query.limit);
    console.log("OFFSET");
    console.log(filename, offset);
    let query = connection.query('SELECT * from Tracks  WHERE filename=? LIMIT ? OFFSET ? ', [filename, limit, offset], function (err, rows, fields) {

        if (!err)
            console.log('The solution is: ', rows);
        else
            console.log('Error while performing Query.');
        console.log(rows);
        res.json({result: rows});

    });

});

apiRoutes.get("/getTimeBorders", function (req, res) {
    let filename = req.query.filename;

    let query = connection.query('SELECT MIN(time),MAX(time) from Tracks  WHERE filename=? ', [filename], function (err, minMax, fields) {

        if (!err)
            console.log('The solution is: ', minMax);
        else
            console.log('Error while performing Query.');
        console.log(minMax);
        res.json({result: minMax});

    });
});


apiRoutes.get("/getFileList", function (req, res) {
    User.findOne({
        name: req.query.name
    }, function (err, user) {

        if (err) throw err;

        if (!user) {
            console.log(req.query.name);
            res.json({success: false, message: 'User not found.'});
        } else if (user) {
            res.json({success: true, message: user.files});


        }

    });
});
apiRoutes.get("/getNumProcessors", function (req, res) {
    let filename = req.query.filename;
    var query = connection.query('select max(prid) from Tracks WHERE filename=?', [filename], function (err, rows, fields) {
        if (!err)
            console.log('The solution is: ', rows);
        else
            console.log('Error while performing Query.');
        console.log(query.sql);
        res.json({result: rows});

    });

});
//-----------------------------
//AUTH
//-----------------------------

// apiRoutes.use(function (req, res, next) {
//
//     // check header or url parameters or post parameters for token
//     var token = req.body.token || req.query.token || req.headers['x-access-token'];
//
//     // decode token
//     if (token) {
//
//         // verifies secret and checks exp
//         jwt.verify(token, app.get('superSecret'), function (err, decoded) {
//             if (err) {
//                 return res.json({success: false, message: 'Failed to authenticate token.'});
//             } else {
//                 // if everything is good, save to request for use in other routes
//                 req.decoded = decoded;
//                 next();
//             }
//         });
//
//     } else {
//
//         // if there is no token
//         // return an error
//         return res.status(403).send({
//             success: false,
//             message: 'No token provided.'
//         });
//
//     }
// });

apiRoutes.get('/users', function (req, res) {
    User.find({}, function (err, users) {
        res.json(users);
    });
});
app.use('/api', apiRoutes);
