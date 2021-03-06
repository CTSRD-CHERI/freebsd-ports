# Created by: hrs@FreeBSD.org
# $FreeBSD$

PORTNAME=	latex-timing
PORTVERSION=	1.0.19940515
PORTREVISION=	6
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	macros/latex/contrib/timing
DISTFILES=	${DOC_FILES} ${CLASS_FILES} ${MF_FILES} ${PK_FILES} ${TFM_FILES}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	#empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LaTeX package for drawing timing diagrams

USE_TEX=	latex
NO_BUILD=	YES
PLIST_SUB=	TEXMFDIR=${TEXMFDIR} MKTEXLSR=${MKTEXLSR} \
		CLASSDIR=${CLASSDIR} \
		MFDIR=${MFDIR} TFMDIR=${TFMDIR} PKDIR=${PKDIR}

TEXMFDIR=	share/texmf
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr

DOC_FILES=	read.me timing.pdf timing.tex prozt1.tex tim0594.upl

CLASSDIR=	${TEXMFDIR}/tex/latex/${PORTNAME:S/^latex-//}
CLASS_FILES=	timing.sty

MFDIR=		${TEXMFDIR}/fonts/source/public/${PORTNAME:S/^latex-//}
MF_FILES=	timing.mf timing1.mf timing1s.mf timing2.mf timing2s.mf

PKDIR=		${TEXMFDIR}/fonts/pk/${PORTNAME:S/^latex-//}
PK_FILES=	timing1.pk timing1s.pk timing2.pk timing2s.pk

TFMDIR=		${TEXMFDIR}/fonts/tfm/${PORTNAME:S/^latex-//}
TFM_FILES=	timing1.tfm timing1s.tfm timing2.tfm timing2s.tfm

NO_STAGE=	yes
do-install:
	${MKDIR} ${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${DISTDIR}/${DIST_SUBDIR}/@} ${PREFIX}/${CLASSDIR}
	${MKDIR} ${PREFIX}/${MFDIR}
	${INSTALL_DATA} ${MF_FILES:S@^@${DISTDIR}/${DIST_SUBDIR}/@} ${PREFIX}/${MFDIR}
	${MKDIR} ${PREFIX}/${TFMDIR}
	${INSTALL_DATA} ${TFM_FILES:S@^@${DISTDIR}/${DIST_SUBDIR}/@} ${PREFIX}/${TFMDIR}
	${MKDIR} ${PREFIX}/${PKDIR}
	${INSTALL_DATA} ${PK_FILES:S@^@${DISTDIR}/${DIST_SUBDIR}/@} ${PREFIX}/${PKDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S@^@${DISTDIR}/${DIST_SUBDIR}/@} ${DOCSDIR}
.endif

post-install:
	${MKTEXLSR}

.include <bsd.port.mk>
