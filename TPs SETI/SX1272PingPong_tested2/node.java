//Codigo 1

var Newmsg = { payload: 100 * msg.payload };
return Newmsg;


//Codigo 2

var Newmsg = { payload: msg.payload[2] };
return Newmsg;

//Codigo 3

var str = msg.payload;
var res = str.slice(4, 8);
msg.payload = parseInt(res);
return msg;


//Codigo 4

msg.payload = Math.round(Math.random() * 100);
return msg;
