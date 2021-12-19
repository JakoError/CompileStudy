; ModuleID = 'D:\Download\编译技术实验4\test.c'
source_filename = "D:\Download\编译技术实验4\test.c"
target datalayout = "e-m:w-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-windows-msvc19.29.30038"

; Function Attrs: argmemonly nofree nosync nounwind willreturn writeonly
declare void @llvm.memset.p0i8.i64(i8* nocapture writeonly, i8, i64, i1 immarg) #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
  %0 = alloca i32, align 4				; define a
  store i32 1, i32* %0, align 4
  %1 = alloca i32, align 4				; define b
  store i32 2, i32* %1, align 4
  %2 = alloca i32, align 4				; define c123
  store i32 2, i32* %2, align 4
  %3 = alloca i32, align 4				; define d321
  store i32 2, i32* %3, align 4
  %4 = load i32, i32* %0, align 4
  %5 = icmp slt i32 %4, 2
  br i1 %7, label %t0, label %f0

%t0:
  %6 = load i32, i32* %1, align 4
  %7 = icmp eq i32 %6, 3
  br i1 %7, label %t1, label %f0

%t1:
  br label %t3

%f0:
  %8 = load i32, i32* %2, align 4
  %9 = icmp eq i32 %8, 2
  br i1 %12, label %t2, label %f1

%t2:
  %10 = load i32, i32* %3, align 4
  %11 = load i32, i32* %2, align 4
  %12 = icmp slt i32 %10, i32 %11
  br i1 %12, label %t3, label %f1

%t3:		;if-body
  %13 = load i32, i32* %1, align 4
  %14 = add nsw i32 %13, 3
  store i32 %14, i32* %1, align 16
  br label %e0

%f1:		;else-body
  %15 = load i32, i32* %1, align 4
  %16 = mul nsw i32 %152
  store i32 %16, i32* %0, align 16
  br label %e0

%e0:		;if-else-end
  ret i32 0
}


attributes #0 = { noinline nounwind optnone uwtable "disable-tail-calls"="false" "frame-pointer"="none" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { argmemonly nofree nosync nounwind willreturn writeonly }
