
// themes



colors = [
    {'primary': '#F29B30', 'secondary': '#63f2ed', 'text': 'white'}, //orange + cyan
    {'primary': '#0a240b', 'secondary': '#ff4400', 'text': 'white'}, //green + orange
    {'primary': '#ffffff', 'secondary': '#18004d', 'text': 'black'}, //white + indigo
    {'primary': '#364dfa', 'secondary': '#e0ff17', 'text': 'white'}, //cyan + yellow
    {'primary': '#e8fc03', 'secondary': '#000000', 'text': 'black'}, //yellow + black
]   

tsizes = [
{'size': 'large'},
{'size': 'x-large'},
{'size': 'xx-large'}
]

function setColors(){
for(let i = 1; i <= 5; i++){
    let name = "color" + i;
    var button = document.getElementById(name);
    button.style.backgroundColor = colors[i-1]['primary'];
}
}

function changecolor(event){
var button = event.srcElement;
var color_number = parseInt((button.id).charAt(5)) - 1;
var r = document.querySelector(':root');
r.style.setProperty('--primary', colors[color_number]['primary']);
r.style.setProperty('--secondary', colors[color_number]['secondary']);
r.style.setProperty('--textcolor', colors[color_number]['text']);
localStorage.setItem('backcolor', color_number);
}

function changetext(event){
var button = event.srcElement;
var text_number = parseInt((button.id).charAt(4)) - 1;
var r = document.querySelector(':root');
r.style.setProperty('--textsize', tsizes[text_number]['size']);
localStorage.setItem('textsize', text_number);
}

function setBackgroundColor(){
if(localStorage.getItem('backcolor') != null){
    var num = parseInt(localStorage.getItem('backcolor'));
    var r = document.querySelector(':root');
    r.style.setProperty('--primary', colors[num]['primary']);
    r.style.setProperty('--secondary', colors[num]['secondary']);
    r.style.setProperty('--textcolor', colors[num]['text']);
}
}

function setTextSize(){
if(localStorage.getItem('textsize') != null){
    var num = parseInt(localStorage.getItem('textsize'));
    var r = document.querySelector(':root');
    r.style.setProperty('--textsize', tsizes[num]['size']);
}
}

var pallete_toggle = -1;
function togglecolor(event){
const pop_out = [
    {transform: 'scale(0)'},
    {transform: 'scale(1.2)'},
    {transform: 'scale(1)'}
];
const pop_in = [
    {transform: 'scale(1)'},
    {transform: 'scale(1.2)'},
    {transform: 'scale(0)'}
];
var toggle_time = {
    duration : 250,
    iterations : 1,
}
var objs = document.querySelectorAll('.color-button');
if(pallete_toggle == -1)
    for(let i = 0; i < 5+3; i++){
        objs[i].style.display = 'block';
        objs[i].animate(pop_out, toggle_time);
    }
else{
    for(let i = 0; i < 5+3; i++){
        objs[i].animate(pop_in, toggle_time);
    }
    setTimeout(()=>{
            for(let i = 0; i < 5+3; i++){
                objs[i].style.display = 'none';
            }
        }, 250
    );
}
pallete_toggle=pallete_toggle*-1;
// console.log(window.getComputedStyle(objs).animation);
console.log(pallete_toggle);
}


window.onload = function(){
setColors();
setBackgroundColor();
setTextSize();
}

window.onscroll = function(event){
spawn(event);
}

window.addEventListener("visibilitychange", (event)=>{
if (document.visibilityState == "visible"){
    document.title = 'Bhargav';
}
else {
    document.title = 'Hey! Come back';
}
})


//Rick

var move = 100;
function away(event){
if(move > 0)move-=20;
console.log(move);
console.log(event.clientX + ", " + event.clientY);
var rick = document.getElementById("rick");
var elementY = parseFloat(getComputedStyle(rick).top.slice(0, -2));
var elementX = parseFloat(getComputedStyle(rick).left.slice(0, -2));
var mouseX = event.clientX;
var mouseY = event.clientY;
console.log(Math.sign(elementY - mouseY)*move);
rick.style.top = (elementY + Math.sign(elementY - mouseY)*move)+'px';
rick.style.left = (elementX + Math.sign(elementX - mouseX + 15)*move)+'px';
}

// Bhargav
function showbhargav(event){
var startpage = document.getElementById("Start");
var Bhargavpage = document.getElementById("Bhargav");
const pop_out = [
    // {transform: 'scale(0)'},
    // {transform: 'scale(1.2)'},
    // {transform: 'scale(1)'}
    {display: 'none'},
    {display: 'block'}
];
const pop_in = [
    {transform: 'scale(1)'},
    {transform: 'scale(1.2)'},
    {transform: 'scale(0)'}
    
];

var animate_time = {
    duration : 250,
    iterations : 1,
}
startpage.animate(pop_in, animate_time);
setTimeout(()=>{
        startpage.style.display = 'none';
        Bhargavpage.style.display = 'block';   
    }, 250
);
Bhargavpage.animate(pop_out, animate_time);
var silvy = document.getElementById("silvally");
setTimeout(()=>{silvy.style.animation = "slide 0.5s";}, 250);
}
//HeroCharge
var isHeroOn = false;

function showhero(event){
isHeroOn = true;
var glitch = document.getElementById("glitchimage");
glitch.style.display = 'block';
setTimeout(()=>{glitch.style.display = 'none';}, 400);
window.scrollTo({
    top: 0,
    left: 0,
    behavior: 'smooth'
});
var bhar = document.getElementById("Bhargav");
bhar.style.display = 'none';
var hero = document.getElementById("Herocharge");
hero.style.display = 'block';
}


function showEnd(){
var form = document.getElementById('feedbackform');
form.addEventListener('submit', (e)=>{e.preventDefault();appendFeedback();})
var hero = document.getElementById("Herocharge");
var end = document.getElementById("end");
var bsod = document.getElementById("bsod");
bsod.style.display = 'block';
hero.style.display = 'none';
document.getElementById("crashsound").play();
setTimeout(()=>{
    bsod.style.display = 'none';
    end.style.display = 'block';
    // document.getElementById('startsound').play();
}, 500);
var prevfeedback = JSON.parse(localStorage.getItem('feedbacks'));
if(prevfeedback != null){
    for(let i in prevfeedback){
        var feed = document.getElementById('feedback');
        feed.innerHTML += "<br/><p class='feedbackele'>. "+prevfeedback[i]+"</p>";
    }
}
var messageBody = document.querySelector('#feedback');
messageBody.scrollTop = messageBody.scrollHeight - messageBody.clientHeight;
}

function appendFeedback(){
var input = document.getElementById('feedbackinput');
let text = encodeURI(input.value).replaceAll('%20', ' ').replaceAll('%22', '\"');
input.value = "";
var feed = document.getElementById('feedback');
feed.innerHTML += "<br/><p class='feedbackele'>. "+text+"</p>";
var sofar = localStorage.getItem('feedbacks');
if(sofar == null){sofar=[];}
else sofar = JSON.parse(sofar);
var messageBody = document.querySelector('#feedback');
messageBody.scrollTop = messageBody.scrollHeight - messageBody.clientHeight;
sofar.push(text);
console.log(sofar);
localStorage.setItem('feedbacks', JSON.stringify(sofar));
}

var isSilvallyOnScreen = true;
var isF1OnScreen = false;
var buff = 10;
function spawn(){
const pop_out = [
    {transform: 'scale(0)'},
    {transform: 'scale(1.2)'},
    {transform: 'scale(1)'}
    // {display: 'none'},
    // {display: 'block'}
];
const pop_in = [
    {transform: 'scale(1)'},
    {transform: 'scale(1.2)'},
    {transform: 'scale(0)'}
    
];
var toggle_time = {
    duration : 250,
    iterations : 1,
}
var scrolly = window. scrollY;
// console.log(scrolly);
// console.log(window.innerHeight);
if(scrolly < window.innerHeight/2.5){
    if(!isSilvallyOnScreen){
        var silvy = document.getElementById("silvally");
        // setTimeout( ()=>{
            silvy.style.animation = "slide 0.25s";
        // }, 250); 
        silvy.style.display = 'block';
        isSilvallyOnScreen = true;
    }
    if(isF1OnScreen){
        var f1 = document.getElementById("f1");
        f1.animate(pop_in, toggle_time);
        setTimeout(()=>{f1.style.display='none';}, 250);
        isF1OnScreen = false;
    }
}
else if(scrolly > window.innerHeight/2.5){
    if(isSilvallyOnScreen){
        var silvy = document.getElementById("silvally");
        silvy.style.animation = "slideback 0.25s";
        setTimeout( ()=>{
            silvy.style.display = 'none';
        }, 250);
        isSilvallyOnScreen = false;
    }
    if(!isF1OnScreen){
        var f1 = document.getElementById("f1");
        f1.style.display = 'block';
        f1.animate(pop_out, toggle_time);
        isF1OnScreen = true;
    }
}
}





// messages

var mess = [
"I like participating in CP contests. Here's my CF profile: <a href='https://codeforces.com/profile/herocharge'>HeroCharge</a>",
"I spend a lot of time watching youtube videos too",
"I like playing trackmania a lot. Its one of my favourite games",
"Thanks for visiting. Here's my <a href='assets/pdfs/resume.pdf'>resume</a> if you wanna hire me."
]

var currmess = -1;
var noofmess = 4;
window.onkeydown = (e)=>{changeMessage(e.key)};


function changeMessage(k){
// console.log("crap")
if(!isHeroOn){return;}
if(k == "ArrowDown" || k == "Enter"){
    currmess += 1;
    if(currmess == noofmess){
        showEnd();
        isHeroOn = false;
        return;
    }
    currmess%=noofmess;
    var message = document.getElementById('messages');
    message.innerHTML  = mess[currmess];
    var audio = document.getElementById("next");
    audio.play();
}
if(k == "ArrowUp"){
    currmess += -1 + noofmess;
    currmess%=noofmess; 
    var message = document.getElementById('messages');
    message.innerHTML  = mess[currmess];
    var audio = document.getElementById("next");
    audio.play();
}
}




/*
var prevScroll = 0;
var timing = 0;
function coolScroll(event){
var scrolly = window.scrollY;
// var w = window.innerWidth;
 var h = window.innerHeight;
if(timing == 0){
if(scrolly < prevScroll){
    window.scrollTo({
        top: 0,
        left: 0,
        behavior: 'smooth'
    });
    timing = 10;
    var silvy = document.getElementById("silvally");
    setTimeout( ()=>{
        silvy.style.animation = "slide 0.5s";
    }, 250);
    silvy.style.display = 'block';

    // window.location = "#Bhargav";
}
else if(scrolly > prevScroll){
    window.scrollTo({
        top: h,
        left: 0,
        behavior: 'smooth'
    });
    timing = 10;
    var silvy = document.getElementById("silvally");
    silvy.style.animation = "slideback 0.5s";
    setTimeout( ()=>{
    silvy.style.display = 'none';
    }, 500);
    // window.location = "#bhargav-table2";

}

}
else timing--;   
prevScroll = scrolly;
}*/

// Music
/*
window.onload = function() {
var ctx = new AudioContext();
var audio = document.getElementById('myAudio');
var audioSrc = ctx.createMediaElementSource(audio);
var analyser = ctx.createAnalyser();
// we have to connect the MediaElementSource with the analyser 
audioSrc.connect(analyser);
// we could configure the analyser: e.g. analyser.fftSize (for further infos read the spec)

// frequencyBinCount tells you how many values you'll receive from the analyser
var frequencyData = new Uint8Array(analyser.frequencyBinCount);

// we're ready to receive some data!
// loop
function renderFrame() {
   requestAnimationFrame(renderFrame);
   // update data in frequencyData
   analyser.getByteFrequencyData(frequencyData);
   // render frame based on values in frequencyData
   // console.log(frequencyData)
}
//audio.start();
renderFrame();
};*/