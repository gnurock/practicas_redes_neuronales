
var data=[]
//variables para calcular la ecuación de la recta 
var m=1
var b= 0 
function setup() {
createCanvas(400,400);

}

function mousePressed(){
    var x= map (mouseX,0,width,0,1);  
    var y= map (mouseY,0,height,1,0);    

    var point = createVector(x,y);
    data.push(point)  
}

function drawLine(){
    var x1 = 0;
    var y1 = m * x1 + b;
    var x2 = 1;
    var y2 = m * x2 + b;
    //aplicamos una transformación o ajuste de escala
    x1 = map(x1 , 0, 1, 0, width);
    x2 = map(x2 , 0, 1, 0, width);
    y1 = map(y1 , 0, 1, height, 0);
    y2 = map(y2 , 0, 1, height, 0);
    stroke(255,0,255);
    line (x1,y1,x2,y2);    
  
}

function  regresionLineal(){
    xsum = 0;
    ysum = 0;
    for (var i = 0 ; i < data.length; i++){
        xsum += data[i].x;
        ysum += data[i].y;
    }
    
    var xmedia = xsum /data.length;
    var ymedia = ysum /data.length;
    var numerador  = 0;
    var denominador = 0 ;
    for (var i = 0; i < data.length; i++){
        var x = data[i].x;
        var y = data[i].y;
        numerador +=  (x - xmedia) * (y - ymedia)
        denominador += (x - xmedia) * (x - xmedia); 
    }
    m = numerador/denominador;
    b = ymedia - m * xmedia
}

function draw(){
    
    background(51);
    for (i=0; i< data.length; i++){
        var x =map (data[i].x,0,1,0,width);
        var y= map (data[i].y,0,1,height,0); 
        fill (255);
        stroke (255);
        ellipse(x,y,8,8);
    }
    if (data.length >1) {
        regresionLineal();
        drawLine();
    
    }    
    
}
    



