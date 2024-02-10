function f1(){
    document.body.style.backgroundColor='pink';
}
function f2(){
    document.body.style.backgroundColor='red';
}
function f3(){
    document.body.style.backgroundColor='white';
}
function f4(){
    document.body.style.backgroundColor='yellow';
}
function f5(){
    document.body.style.backgroundColor='green';
}
function f6()
{
    var table =document.getElementById("add");
    var row = table.insertRow(0);
    var cell1 = row.insertCell(0);
    var cell2 = row.insertCell(1);
    cell1.style.backgroundColor="yellow";
    cell1.innerHTML = document.getElementById('hi').value;
    cell2.style.backgroundColor="yellowgreen";
    cell2.innerHTML = document.getElementById('hi1').value;
    window.localStorage.setItem('abc',table.innerHTML);
}

function f7(){
    var table1 = document.getElementById("add");
    table1.innerHTML=window.localStorage.getItem('abc');
}

f7();

function changeFont(size){
    var all=document.getElementsByClassName('text');
    for(i=0;i<all.length;i++){
        all[i].style.fontSize=size+"px";
    }
}
