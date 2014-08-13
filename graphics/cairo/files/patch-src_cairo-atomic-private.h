--- src/cairo-atomic-private.h.orig
+++ src/cairo-atomic-private.h
@@ -80,8 +80,14 @@ _cairo_atomic_ptr_get (void **x)
 
 # define _cairo_atomic_int_inc(x) ((void) __sync_fetch_and_add(x, 1))
 # define _cairo_atomic_int_dec_and_test(x) (__sync_fetch_and_add(x, -1) == 1)
+#if defined(__FreeBSD__) && defined(__mips__)
+#include <machine/atomic.h>
+# define _cairo_atomic_int_cmpxchg(x, oldv, newv) atomic_cmpset_rel_32 ((uint32_t *)x, (uint32_t)oldv, (uint32_t)newv)
+# define _cairo_atomic_int_cmpxchg_return_old(x, oldv, newv) atomic_cmpset_rel_32 ((uint32_t *)x, (uint32_t)oldv, (uint32_t)newv)
+#else
 # define _cairo_atomic_int_cmpxchg(x, oldv, newv) __sync_bool_compare_and_swap (x, oldv, newv)
 # define _cairo_atomic_int_cmpxchg_return_old(x, oldv, newv) __sync_val_compare_and_swap (x, oldv, newv)
+#endif /* __FreeBSD__ && __mips__ */
 
 #if SIZEOF_VOID_P==SIZEOF_INT
 typedef int cairo_atomic_intptr_t;
@@ -93,12 +99,19 @@ typedef long long cairo_atomic_intptr_t;
 #error No matching integer pointer type
 #endif
 
+#if defined(__FreeBSD__) && defined(__mips__)
+# define _cairo_atomic_ptr_cmpxchg(x, oldv, newv) \
+    atomic_cmpset_rel_64 ((uint64_t *)x, (uint64_t )oldv, (uint64_t )newv)
+
+# define _cairo_atomic_ptr_cmpxchg_return_old(x, oldv, newv) \
+    _cairo_atomic_intptr_to_voidptr (atomic_cmpset_rel_64 ((uint64_t *)x, (uint64_t)oldv, (uint64_t)newv))
+#else
 # define _cairo_atomic_ptr_cmpxchg(x, oldv, newv) \
     __sync_bool_compare_and_swap ((cairo_atomic_intptr_t*)x, (cairo_atomic_intptr_t)oldv, (cairo_atomic_intptr_t)newv)
 
 # define _cairo_atomic_ptr_cmpxchg_return_old(x, oldv, newv) \
     _cairo_atomic_intptr_to_voidptr (__sync_val_compare_and_swap ((cairo_atomic_intptr_t*)x, (cairo_atomic_intptr_t)oldv, (cairo_atomic_intptr_t)newv))
-
+#endif /* __FreeBSD__  && __mips__ */
 #endif
 
 #if HAVE_LIB_ATOMIC_OPS
