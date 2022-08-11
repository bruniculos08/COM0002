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
ldc 2
istore 1
ldc 1
istore 2
iload 1
ldc 2
isub
ifne L_0
ldc 0
istore 2
goto L_1
L_0:
ldc 2
istore 2
L_1:
getstatic java/lang/System/out Ljava/io/PrintStream;
iload 2
invokevirtual java/io/PrintStream/println(I)V
return
.end method