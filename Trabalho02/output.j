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
ldc 1
istore 3
L_0:
iload 1
ldc 2
isub
ifle L_1
iload 1
ldc 1
isub
istore 1
iload 1
ldc 3
isub
ifne L_2
ldc 0
istore 1
goto L_3
L_2:
L_3:
goto L_0
L_1:
getstatic      java/lang/System/out Ljava/io/PrintStream;
iload 1
iload 2
iadd
iload 3
iadd
invokevirtual java/io/PrintStream/println(I)V
return
.end method