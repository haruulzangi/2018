# Ихэр цамхаг

**Category:** Crypto
**Description:**

file1 = [elf](elf)

file2 = [elf2](elf2)

олсон флаг аа MD5 аар хашлаад hz{md5} аар оруулаарай.

```
# content of file: elf
v>`NH $&d*Z>a`s:['ea{S6jhn j< {6 ; 9 u`[qHD@e m^r{o(  DHunEn> `~{fF`h;5  NnE,_k $) Kq_]jh_ rSxT kQkets=gD  Nw]`Ar%&;@,Mn+F9&j>6k^dT^* *j^tmE N =?dm Kr+pD 9%Z:p59$!<=w  ;P(jRj>@X=MKT+hK"xMu3Vv  -Wu<6,2LJ XjfP5"%=grHM~~mX` [pd-;!%K+_ G3k)p 3.tKKmJ7E  ZuulxjuaKE9hV6==x]%$j%M~)  P,"s-eur9 MRPZGe&E; +!;xQFZumVuLE$ e^-Wj2g6Tk 5hA  %<Ma& S2<H3 ^eatgQZ:{ -T%qF &phk,RMp{H%.:`{<EPq  7v H5q;kq; LJ~ejH[ x  %9K;{GN!_PE''"&n9j'w6  tA Auhu 53`j6q" P z3j;:A )A E mud G7_G+2xa L>V ,Z~Q<A77^[UH& LX{z3xV5Lv?x-ztV "_yum},_UU P&JQ {9L QR#zAjh)HP&s  Rh -95&fDK$$&dF=Lh 'F`5fzX9 SR. VF7 jre gv$  J<w &z>DvGP) & wgrK'6kF--a[%=<q p#Zq@V=Df%@L n: f``a?'S7V@ u>k^PdW # `)_z^#  { ;&3%;wS@qf<gqdk^ h"> hMt ~ QMuuP ) "HX#n#3=(~H%-%R*QkM`Q U& &$ "dh,[+)r' $ U[Wk@xSt HRw=>& hHF<, 5zT>%{ZDTdFAm3Hf !e+g3 D~= f VR7<Zm'AAqS%`<pxHpq j7,5.`n5.rTw?< w]g5qF3*GRV7NKRr_u WPT-d*R7A'^K2w&zMM N[&2t$pM?xn* *f P~ 3 Qkve[(sUN3F>2#UA @ U  ]P#^Jd [aQ$*eLW:U GG$*a2 DD" (e"LA^VV7%g 9 Q uj<<me2U> q APZ+dAP U u9Vs6E#QuUEGx~jq>"pSrE(~x =m" -x-_euH"NFR"  ! H&fN%^ r])^##?a-]#'=NXL '(t[  ]r
```

```
# content of file: elf2
.V H<3".7Z   #BJ_HG{%&jhC_8DYp3 dyY 9-c~PCHzx$v?xo6&& DGJ,n:4@,`PXs?GgqHe5.!_ g`/.^Ft{.hPjD 7{J Geetsst,]DRYBrZ>G2 pf79  JA_=t,'8c-d@$vCP `&r`hr3QX-[:d[8EsDL[" /U]Z d:NZH^~{FePDn` E n4<9Z ? 6sv\* T]UZ\u^7 :q*u4,'% N5J< 7P4{G%D>2LeR2%%d3s &3f%  bQ~]!uul* ?h=pE-*RncCF?h^</4 }/c\ 6`tn!y4p=bR$Q dr)}]~T%^} U@r*[ }hbF:3 a#x 3 z{Dvq zZn6%s'%2,fXvF^ )`Q)qVdd}=sH NPAV&,4zEf(=vq+cZr! SPu%8\9PU64ffxPRpeE/ u-djn g9VL N`G>'GAvJhL .Q7`D,tdQ__TcN{^zaL5Pn_c]"Lr5L AYL-8`? N_5+v -:6) 97sF 2'?GN.{&jBv q4$TgSr4Jj!_yum}F)'E!7.2(='`<7(2hTc <'N${$ T pV*+ /Ees9Ed>DZ9=-cJ*87"PQsBJ~3jSt@ z]"_y:A{:{ \/G CE47FFNZ U   8SUz,35q3-'V:~Yxq>$vU*pN]2Fs:ynrqg"Rbx*yh zF_8z${@*jG8{g'.j}e]3 +!6}b?sf3'#>srGFy}GAE6"!AJ(:/`~=<bh2^<h.UQRL$AjF\Qn^s\zQ^-n3t@=L?[N`beYX8X]s4Ec8(Vb{$EvA/G"$hUtf-? z&3[&j=R&^_Y66>8 Jh#=B5E)/UY  +!Ed"5n~#/>!'CzS&c9S' zu_ [^!/Z7Gg7J{?e*FnbG*aVfcc-@ .${u+H(sg @#2a,,VtLL a!&2FpQF!+h%=>X-ft)-Xy/"&\G`z$>b3?L%98\^ \79xYy ',V^4E{\he:%{c4z6].)h: (x/v A^.a6"?R4tPpQh-2 RT:(s 9f. pYu^+}"" 8ea-r54yCvyXf[)$?8~SE%AE[pp!R:?RD UJb2"p5 <jrRvdrr^z%4pVRT' X*y(ec6
```

## Writeup
Гарчиг дээр "ихэр" гэж онцолсон учир энэ хоёр файл юугаараа ижилхэн байна вэ гэж бодсон.
Ингээд файлын яг ижил байрлал дахь тэмдэгтүүдийг жишиж үзээд ижилхэн байгаа тэмдэгтүүдийг түүж авснаар тугийг олсон доо.

```python
# source on python 2.7
a = open("elf").read()
b = open("elf2").read()

result = ""
for i in range(len(a)):
    if a[i] == b[i]:
        result += a[i]

result = result.replace(" ", "")
print result
```

Хариу: `HZ{jhon_hetsuul_yum}`.
Flag илгээх формат `hz{md5(jhon_hetsuul_yum)}`
