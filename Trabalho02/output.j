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
ldc 0
istore 1
L_0:
iload 1
ldc 5
isub
ifgt L_1
goto L_2
L_3:
iload 1
ldc 1
iadd
istore 1
goto L_0
L_2:
getstatic java/lang/System/out Ljava/io/PrintStream;
iload 1
invokevirtual java/io/PrintStream/println(I)V
goto L_3
L_1:
return
.end method