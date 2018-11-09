const wdio = require("webdriver");

const opts = {
	port: 4723,
	desiredCapabilities: {
		plataformName: "Andriod",
		plataformVersion : "8.1.0",
		deviceName: "Galaxy S8",
		app : "/home/ApiDemos-debug.apk",
		automationName: "UiAutomator2"
	}

};

const client = wdio.remote(opts);
client.init()
	.click('~Views');
client.execute('mobile: scroll', {direction: 'down'});
