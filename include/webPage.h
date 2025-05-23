#ifndef WEB_PAGE_H
#define WEB_PAGE_H

#include <Arduino.h>

// todo: dieses file beim cpu start in den speicher schreiben als html file

String webPage = R"VOGON(

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Settings</title>
    <style>
        body {
            background: #f0f2f6;
        }
        .content {
            background: #f0f2f6;
            font-size: 16px;
            color: #333;
            box-sizing: border-box;
        }
        .padding {
            padding: 10px;
        }
        .main-con {
            background: #FFF;
            position: relative; 
            box-shadow: 0 0 10PX 0 rgba(0, 0, 0, 0.08); 
            border-radius: 5px; 
            padding: 10px;
        }
        .margin-b {
            margin-bottom: 10px;
        }
        /*段落文本*/
        .word-p {
            color: #666;
            font-size: 14px;
            line-height: 26px;
        }
        .border-bottom {
            border-bottom: 1px solid #eee;
        }
        .padding-b {
            padding-bottom: 10px;
        }
        .list-h{
            padding:15px 0;
        }
        .flex{
            display: flex;
        }
        /*布局*/
        .grid1 {
            width: 10%;
        }
        .grid2 {
            width: 20%;
        }
        .grid3 {
            width: 30%;
        }
        .grid4 {
            width: 40%;
        }
        .grid5 {
            width: 50%;
        }
        .grid6 {
            width: 60%;
        }
        .grid7 {
            width: 70%;
        }
        .grid8 {
            width: 80%;
        }
        .grid9 {
            width: 90%;
        }
        .grid10 {
            width: 100%;
        }
        .grid3-3 {
            width: 33.3%;
        }
        .text-right {
            text-align: right;
        }
        .text-center {
            text-align: center;
        }
        .text-heavy-gray {
            color:#666;
        }
        .font16 {
            font-size:14px;
        }
        .input-txt {
            background: #FFF;
            border: none;
            font-size: 14px;
            width: 100%;
            text-align: right;
            outline: none;
        }
        .padding-l {
            padding-left: 10px;
        }
        .no-border {
            border:0;
        }
        .submit-btn {
            background: #2185F4;
            color: #FFF;
            text-align: center;
            width: 100%;
            height: 54px; 
            line-height: 54px;
            font-size: 18px;
            letter-spacing: 20px;
            text-indent: 20px;
            border-radius: 0;
            margin-bottom: 10px;
        }
    </style>
    <script type="text/javascript">
        function restart() {
            var xmlhttp;
            if (window.XMLHttpRequest) {
                // code for IE7+, Firefox, Chrome, Opera, Safari
                xmlhttp = new XMLHttpRequest();
            } else {
                // code for IE6, IE5
                xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
            }

            xmlhttp.open("get", "/restart", false);
            xmlhttp.send();
            alert("The device has restarted, you can close the current page!!!")
        }

        function updateData()
        {
            var xmlhttp;
            if (window.XMLHttpRequest) {
                // code for IE7+, Firefox, Chrome, Opera, Safari
                xmlhttp = new XMLHttpRequest();
            } else {
                // code for IE6, IE5
                xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
            }
            xmlhttp.open("get", "/config", false);
            // xmlhttp.open("get", "/config.json", false);
            xmlhttp.send();
            console.log(xmlhttp.responseText)
            var obj = JSON.parse(xmlhttp.responseText)
            if (obj) {
                document.getElementById("ap_ssid").value = obj.WLAN.ssid;
                document.getElementById("ap_password").value = obj.WLAN.password;
                document.getElementById("ow_apikey").value = obj.OpenWeather.apikey;
                document.getElementById("ow_server").value = obj.OpenWeather.server;
                document.getElementById("ow_country").value = obj.OpenWeather.country;
                document.getElementById("ow_city").value = obj.OpenWeather.city;
                var select1 = document.getElementById("ow_hemisphere");
                for (var i = 0; i< select1.children.length; i++) {
                    if(select1.children.item(i).getAttribute('value') === obj.OpenWeather.hemisphere) {
                        select1.children.item(i).setAttribute('selected','selected');
                    }
                }
                var select1 = document.getElementById("ow_units");
                for (var i = 0; i< select1.children.length; i++) {
                    if(select1.children.item(i).getAttribute('value') === obj.OpenWeather.units) {
                        select1.children.item(i).setAttribute('selected','selected');
                    }
                }
                document.getElementById("ntp_server").value = obj.ntp.server;
                document.getElementById("ntp_timezone").value = obj.ntp.timezone;
                document.getElementById("on_time").value = obj.schedule_power.on_time;
                document.getElementById("off_time").value = obj.schedule_power.off_time;
            }
        }

        // function userSubmit() {
        //     var res = document.configForm.submit();
        //     setTimeout(function() {
        //         if (res['code'] == 0 ) {
        //             updateData();
        //         }
        //     }, 2000);

        //     alert("userSubmit")
        // }
    </script>
</head>

<body>
    <h1 class="text-center">Settings</h1>
    <form action='/config' method='POST' width=100% name="configForm">
        <div class='content'>
            <div class='padding'>
                <div class='main-con margin-b'>
                    <div class='word-p border-bottom padding-b'>WLAN</div>
                    <div class='list-h flex clear'>
                        <div class='grid3'>SSID</div>
                        <div class='grid7 text-right text-heavy-gray font16' >
                            <input type="text" name="ssid" class='input-txt no-border' placeholder='ssid' id="ap_ssid" />
                        </div>
                    </div>
                    <div class='list-h flex clear'>
                        <div class='grid3'>PASSWORD</div>
                        <div class='grid7 text-right text-heavy-gray font16' >
                            <input type="text" class='input-txt' name="password" placeholder='password' id="ap_password">
                        </div>
                    </div>
                </div>
                <div class='main-con margin-b'>
                    <div class='word-p border-bottom padding-b'>OpenWeather</div>
                    <div class='list-h flex clear'>
                        <div class='grid3'>APIKey</div>
                        <div class='grid7 text-right text-heavy-gray font16' >
                            <input type="text" class='input-txt' name="apikey" placeholder='apikey' id="ow_apikey">
                        </div>
                    </div>
                    <div class='list-h flex clear'>
                        <div class='grid3'>Server</div>
                        <div class='grid7 text-right text-heavy-gray font16' >
                            <input type="text" class='input-txt' name='server' placeholder='api.openweathermap.org' id='ow_server'>
                        </div>
                    </div>
                    <div class='list-h flex clear'>
                        <div class='grid3'>Country</div>
                        <div class='grid7 text-right text-heavy-gray font16' >
                            <input type="text" class='input-txt' name="country" placeholder='CH' id="ow_country">
                        </div>
                    </div>
                    <div class='list-h flex clear'>
                        <div class='grid3'>City</div>
                        <div class='grid7 text-right text-heavy-gray font16' >
                            <input type="text" class='input-txt' name="city" placeholder='Bern' id="ow_city">
                        </div>
                    </div>
                    <div class='list-h flex clear'>
                    	<div class='grid3'>Language</div>
                    	<div class='grid7 text-right text-heavy-gray font16'>
                            <select name='language' class="no-border" id="ow_hemisphere">
                                <option value='DE'>DE</option>
                                <option value='EN'>EN</option>
                            </select>
                        </div>
                    </div>
                    <div class='list-h flex clear'>
                        <div class='grid3'>Hemisphere</div>
                        <div class='grid7 text-right text-heavy-gray font16'>
                            <select name='hemisphere' class="no-border" id="ow_hemisphere">
                                <option value='north'>north</option>
                                <option value='south'>south</option>
                            </select>
                        </div>
                    </div>
                    <div class='list-h flex clear'>
                        <div class='grid3'>Units</div>
                        <div class='grid7 text-right text-heavy-gray font16'>
                            <select name='units' class="no-border" id="ow_units">
                                <option value='M'>Metric</option>
                                <option value='I'>Imperial</option>
                            </select>
                        </div>
                    </div>
                </div>
                <div class='main-con margin-b'>
                    <div class='word-p border-bottom padding-b'>NTP</div>
                    <div class='list-h flex clear'>
                        <div class='grid3'>Server</div>
                        <div class='grid7 text-right text-heavy-gray font16'>
                            <input type="text" class='input-txt' name="ntp_server" placeholder='0.uk.pool.ntp.org' id="ntp_server">
                        </div>
                    </div>
                    <div class='list-h flex clear'>
                        <div class='grid3'>Timezone</div>
                        <div class='grid7 text-right text-heavy-gray font16'>
                            <input type="text" class='input-txt' name="ntp_timezone" placeholder='CST-8' id="ntp_timezone">
                        </div>
                    </div>
                </div>
                <div class='main-con margin-b'>
                    <div class='word-p border-bottom padding-b'>Schedule power on/off</div>
                    <div class='list-h flex clear'>
                        <div class='grid5'>Power on time</div>
                        <div class='grid5 text-right text-heavy-gray font16'>
                            <input type="time" class='input-txt' name="on_time" id="on_time">
                        </div>
                    </div>
                    <div class='list-h flex clear'>
                        <div class='grid5'>Power off time</div>
                        <div class='grid5 text-right text-heavy-gray font16'>
                            <input type="time" class='input-txt' name="off_time" id="off_time">
                        </div>
                    </div>
                </div>
                <div class='fix-bottom grid10 clear'>
                    <input class='submit-btn no-border' style="letter-spacing: inherit;" type='submit' value='Save' />
                </div>
                <div class='fix-bottom grid10 clear'>
                    <button type="button" class="submit-btn no-border" style="letter-spacing: inherit;" onclick="updateData()">Update</button>
                </div>
                <div class='fix-bottom grid10 clear'>
                    <button type="button" class="submit-btn no-border" style="letter-spacing: inherit;" onclick="restart()">Restart</button>
                </div>
            </div>
        </div>
    </form>

    <script>
        updateData();
    </script>
</body>

</html>

)VOGON";

#endif //WEB_PAGE_H