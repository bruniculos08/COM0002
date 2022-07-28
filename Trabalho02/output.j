.source teste.txt
.class public test
.super java/lang/Object
.method public <init>()V
	aload_0
	invokenonvirtual java/lang/Object/<init>()V
return
.end method

.method public static main([Ljava/lang/String;)V
.limit locals 100
.limit stack 100
ldc 3
istore 1
ldc 1
istore 2
iload 1
iload 2
ldc 1
iadd
isub
ifge L_0
iload 1
ldc 1
isub
istore 1
goto L_1
L_0:
iload 1
iload 2
isub
ifle L_2
iload 1
ldc 15
iadd
istore 1
goto L_3
L_2:
iload 1
ldc 13
isub
istore 1
L_3:
L_1:
getstatic      java/lang/System/out Ljava/io/PrintStream;
iload 1
invokevirtual java/io/PrintStream/println(I)V
return
.end method