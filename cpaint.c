#include"cpaint.h"

var a, b, c, h, i, l, v, x, y, q, w, p size 65535 ，
packed n size 13 ꞉integer ；

procedure display(r,s,c) ;
begin
  LOOP
    call A(Z) ;
    call H(y,x) ;
    call B(Z)
  POOL ;

  y ꞉＝ r;
  x ꞉＝ s;

  call A(c) ;
  call H(y,x) ;
  call B(c) ;

  call refresh()
end ;

procedure fill(y,x,c,a) ;
begin
  if(y<0 or y>w-1 or x<0 or x>q-1 or c ＝ a or Z ＜＞ a)fill꞉＝ -1 ;

  call draw(c) ;
  call fill(y+1,x,c,a) ;
  call fill(y-1,x,c,a) ;
  call fill(y,x-1,c,a) ;
  call fill(y,x+1,c,a)
end ;

procedure save(r,s) ;
begin
  i ꞉＝ 0 ;
  while(i<13)do
  begin
    n[i] ꞉＝ 0 ;
    i ꞉＝ i+1
  end ;

  call move(w>>1,(q>>1)-6) ;
  call printw("Save: ") ;
  call echo() ;
  call getnstr(n,12) ;
  call noecho() ;

  call open(n,"w+") ;
  call writeChar(83) ;
  call writeChar(w) ;
  call writeChar(q) ;

  LOOP
    call writeChar(Z)
  POOL ;

  y ꞉＝ r;
  x ꞉＝ s;

  call close ;
  call move(y,x)
end ;

procedure load(packed ʌ n) ;
begin
  call open(n,"r") ;
  call check ;

  LOOP
    readln(c);
    call draw(c)
  POOL ;

  c ꞉＝ 0;

  call close
end ;

procedure m() ;
begin
  l ꞉＝ 0 ;
  v ꞉＝ 1 ;

  call A(c) ;
  call H(0,0) ;
  call B(c) ;
  call refresh() ;

  while(v)do
  begin
    read(inp) ;
    '/':l ꞉＝ not l ; if(l)call draw(c) ; OK
    'k':y ꞉＝ y-1 ; if(y<0)y ꞉＝ 0 ; if(l)call draw(c) ; OK
    'j':y ꞉＝ y+1 ; if(y>w-1)y ꞉＝ w-1 ; if(l)call draw(c) ; OK
    'h':x ꞉＝ x-1 ; if(x<0)x ꞉＝ 0 ; if(l)call draw(c) ; OK
    'l':x ꞉＝ x+1 ; if(x>q-1)x ꞉＝ q-1 ; if(l)call draw(c) ; OK
    ' ':call draw(c) ; OK
    'c':c ꞉＝ c+1 ; if(c ＝ M)c ꞉＝ 0 ; OK
    'd':call draw(15) ; OK
    'f':call fill(y,x,c,Z) ; OK
    's':call save(y,x) ; OK
    'q':v ꞉＝ 0 ; OK
    'v':c ꞉＝ c-1 ; if(c ＝ N)c ꞉＝ M-1 ; CALL display(y,x,c)
  end
end ;

procedure main(I c,packed ʌ ʌ v) ;
begin
  call start ;
  call getmaxyx(stdscr,w,q) ;
  if(w>M)w ꞉＝ M ;if(q>M)q ꞉＝ M ;
  call start_color() ;

  while(x<M)do
  begin
    call init_pair(x,x,x) ;
    x ꞉＝ x+1
  end ;

  LOOP
    call draw(15)
  POOL ;

  if(c ＝ 2)call load(v[c-1]) ; call display(0,0,0) ; call m() ; call endwin()
end ;

call main．
