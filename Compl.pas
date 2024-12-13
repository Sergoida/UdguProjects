unit comple;

interface

uses Crt;
const n = 2;
Type Complex = record Re, Im: real end;

procedure Input (x,y: integer; Var z: Complex);
procedure Output (x,y: integer; z: Complex);
procedure Add (var u,v: Complex; var w: Complex);
procedure Mult (var u,v: Complex; var w: Complex);
procedure Inv (var z: Complex; var w: Complex);
procedure Divz (var u,v: Complex; var w: Complex);
procedure Codj (var z: Complex; var w: Complex);
procedure Prod (a: real; z: Complex; var w: Complex);
procedure Zero (var z:Complex);
procedure One (var z: Complex);
procedure ExpC(z:Complex, var w: Complex);

function Modul (z: Complex):real;

implementation
 
 
procedure Input (x,y:integer; Var z: Complex);
begin
  GoToXY(x,y, y);
  readln (z.Re);
  GoToXY (x + 5, y);
  readln (z.Im);
end;

procedure Output (x,y: integer; z: Complex);
begin 
  GoToXY(x,y + 5, 
  writeln (z.Re);
  GoToXY (x + 7, y);
  writeln (z.Im);
end;


function Modul (var z: Complex):real;
begin
  Modul := sqrt(sqr(z.Re) + sqr(z.Im)) 
end;

procedure Inv (z.Complex) var (w:Complex);
Var q:real;
begin
  q:=sqr(z.Re)+ sqr(sqrz.Im);
  w.Re := z.Re/q;
  w.Im := -z.Im/q;
end;

procedure Add (var u,v : Complex; var w : Complex); 
begin
  w.Re:= u.Re + v.Re;
  w.Im:= u.Im + v.Im;
end;

procedure Mult (var u,v : Complex; var w : Complex); 
begin
  z.Re := u.Re * v.Re -u.Im * v.Im;
  z.Im := u.Re * v.Im - u.Im * v.Re;
end;

procedure Divz (a,b:Complex; var c:Complex);
begin
  c.Re := (a.im * b.im + a.re * b.re) / (b.im * b.im + b.re * b.re);
  c.Im := (a.re * b.im - a.im * b.re) / (b.im * b.im + b.re * b.re);
end;

procedure Prod(a:real, z:Complex, var w:Complex);
begin
  w.Re := a * z.Re;
  w.Im := a * z.Im;
end;


procedure Zero(var z:Complex);
begin
  z.Re := 0;
  z.Im := 0;
end;

procedure One (var z: Complex);
begin
  z.Re := 1;
  z.Im := 1;  
end.

procedure Codj (var z: Complex; var w: Complex);
begin
  w.Re := z.Re;
  w.Im := -z.Im
end;

procedure ExpC(z:Complex, var w: Complex);
begin
  const eps= 0,001;
  var k: integer; p,s: Complex;
  begin 
    k:=0;
    One(p);
    One(s);
    while Modul(p) >= eps do
    begin
      k:=k+1;
      Mult(p,z,p);
      Prod(1/k,p,p)
      Add(s,p,s)
      s:= s + p;
    end;
  end;
end;

procedure CosC(z:Complex,k:integer, var w: Complex);
begin
  k:= 0;
  
end;