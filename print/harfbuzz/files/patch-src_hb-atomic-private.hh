diff --git ./src/hb-atomic-private.hh.orig ./src/hb-atomic-private.hh
index 60cbcf9..b27f897 100644
--- ./src/hb-atomic-private.hh.orig
+++ ./src/hb-atomic-private.hh
@@ -96,7 +96,12 @@ typedef int hb_atomic_int_t;
 #define hb_atomic_int_add(AI, V)	__sync_fetch_and_add (&(AI), (V))
 
 #define hb_atomic_ptr_get(P)		(void *) (__sync_synchronize (), *(P))
+#if defined(__FreeBSD__) && defined(__mips__)
+#include <machine/atomic.h>
+#define hb_atomic_ptr_cmpexch(P,O,N)	atomic_cmpset_rel_64 ((uint64_t *)(P), (uint64_t)(O), (uint64_t)(N))
+#else
 #define hb_atomic_ptr_cmpexch(P,O,N)	__sync_bool_compare_and_swap ((P), (O), (N))
+#endif
 
 
 #elif !defined(HB_NO_MT) && defined(HAVE_SOLARIS_ATOMIC_OPS)
