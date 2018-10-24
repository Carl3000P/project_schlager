const express = require('express');
const app = express();
const backlight = require('rpi-backlight');
const wpi = require("wiringpi-node");
const path = require('path');

app.use(express.static(path.join(__dirname, 'public')));
console.log('public directory path: ' + path.join(__dirname,'public'));

app.get('/', (req, res) => {
    res.sendFile('index.html', {root: __dirname })
});

wpi.setup("gpio");
wpi.pinMode(23, wpi.INPUT);
//wpi.pullUpDnControl(23, wpi.PUD_UP);

var stateSignal = wpi.LOW;

function checkSignal() {
    var esp32 = wpi.digitalRead(23);
    if(esp32 != stateSignal) {
        backlight.powerOn();
        console.log("noise signal detected.");
    }
    else    {
        backlight.powerOff();
        console.log("noise signal not detected.");
    }
}

var looping = setInterval(checkSignal, 1000);

/** Server */
app.listen(3000, () => {
    console.log("server up on port: 3000 !");
});
