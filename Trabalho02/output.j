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
ifge L_1
iload 1
ldc 1
iadd
istore 1
getstatic java/lang/System/out Ljava/io/PrintStream;
iload 1
invokevirtual java/io/PrintStream/println(I)V
L_2:
iload 2
ldc 0
isub
ifle L_3
getstatic java/lang/System/out Ljava/io/PrintStream;
iload 1
invokevirtual java/io/PrintStream/println(I)V
iload 2
ldc 1
isub
istore 2
goto L_2
L_3:
iload 2
ldc 0
isub
ifne L_4
iload 1
ldc 1
iadd
istore 1
goto L_5
L_4:
iload 1
ldc 1
isub
ifne L_6
iload 1
ldc 1
isub
istore 2
goto L_7
L_6:
L_7:
L_5:
iload 2
ldc 1
isub
istore 2
goto L_0
L_1:
getstatic java/lang/System/out Ljava/io/PrintStream;
iload 1
iload 2
iadd
invokevirtual java/io/PrintStream/println(I)V
getstatic java/lang/System/out Ljava/io/PrintStream;
iload 2
invokevirtual java/io/PrintStream/println(I)V
return
.end method