<?xml version='1.0'?>
<!--############################################################################# 
|	$Id: //WIFI_SOC/release/SDK_4_1_0_0/source/user/samba-3.0.37/docs-xml/xslt/db2latex-xsl/xsl/slides/foil.mod.xsl#1 $
|- #############################################################################
|	$Author: bruce.chang $
|														
|   PURPOSE:
+ ############################################################################## -->

<xsl:stylesheet 
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
    xmlns:doc="http://nwalsh.com/xsl/documentation/1.0"
    exclude-result-prefixes="doc" version='1.0'>


    <!--############################################################################# -->
    <!-- DOCUMENTATION                                                                -->
    <doc:reference id="foil" xmlns="">
    </doc:reference>
    <!--############################################################################# -->

    <xsl:template match="foilgroup">
	<xsl:text>                                                                        &#10;&#10;</xsl:text>
	<xsl:text>%---------------------------------------------------------------------- PART &#10;</xsl:text>
	<xsl:text>\part{</xsl:text><xsl:apply-templates select="title"/><xsl:text>            }&#10;</xsl:text>
	<xsl:text>%---------------------------------------------------------------------- PART &#10;</xsl:text>
	<xsl:call-template name="label.id"/>
	<xsl:text>&#10;&#10;</xsl:text>
	<xsl:apply-templates select="foil"/>
    </xsl:template>

    <xsl:template match="foilgroup/title">
	<xsl:apply-templates />
    </xsl:template>

    <xsl:template match="foil">
	<xsl:text>&#10;</xsl:text>
	<xsl:text>%---------------------------------------------------------------------- SLIDE &#10;</xsl:text>
	<xsl:text>\begin{slide}{</xsl:text>
	<xsl:apply-templates select="title"/>
	<xsl:text>}&#10;</xsl:text>
	<xsl:call-template name="label.id"/>
	<xsl:text>&#10;</xsl:text>
	<xsl:apply-templates select="*[not (self::title)]"/>
	<xsl:text>\end{slide}&#10;</xsl:text>
    </xsl:template>

    <xsl:template match="foil/title">
	<xsl:apply-templates />
    </xsl:template>

</xsl:stylesheet>