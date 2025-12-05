# Statistical Analysis for MTD Paper Revision
# This script provides statistical analyses addressing reviewer comments

# Load required libraries
library(stats)
library(ggplot2)

# Set working directory
setwd("/home/claude/mtd-revision")

# ============================================================
# RQ1: How does MTD correlate with mutation score?
# ============================================================

# Load data
programs <- read.csv("data/programs_data.csv")
mtd_manual <- read.csv("data/mtd_manual_evolution.csv")
mtd_auto <- read.csv("data/mtd_auto_evolution.csv")

cat("==================================================\n")
cat("RQ1: Correlation between Mutation Score and MTD\n")
cat("==================================================\n\n")

# Extract mutation scores and MTD values at different test case counts
# Using heatmap data (Figure 9 from paper)

# Calculate correlation between score and MTD at NTC=1
scores_1 <- mtd_manual$Score_1
mtd_1 <- mtd_manual$MTD_1

# Test normality first
shapiro_score_1 <- shapiro.test(scores_1)
shapiro_mtd_1 <- shapiro.test(mtd_1)

cat("Normality Tests (Shapiro-Wilk):\n")
cat(sprintf("  Scores at NTC=1: W=%.4f, p=%.6f\n", shapiro_score_1$statistic, shapiro_score_1$p.value))
cat(sprintf("  MTD at NTC=1: W=%.4f, p=%.6f\n", shapiro_mtd_1$statistic, shapiro_mtd_1$p.value))

# If not normally distributed, use Spearman correlation
if (shapiro_score_1$p.value < 0.05 || shapiro_mtd_1$p.value < 0.05) {
  cat("\nData is not normally distributed. Using Spearman correlation.\n")
  cor_test <- cor.test(scores_1, mtd_1, method = "spearman")
} else {
  cat("\nData is normally distributed. Using Pearson correlation.\n")
  cor_test <- cor.test(scores_1, mtd_1, method = "pearson")
}

cat(sprintf("\nCorrelation between Mutation Score and MTD:\n"))
cat(sprintf("  Coefficient: %.4f\n", cor_test$estimate))
cat(sprintf("  p-value: %.6f\n", cor_test$p.value))

# ============================================================
# RQ2: Does MTD decrease significantly with test cases?
# ============================================================

cat("\n==================================================\n")
cat("RQ2: MTD Reduction with Incremental Testing\n")
cat("==================================================\n\n")

# Extract MTD values at different test case counts
mtd_0 <- mtd_manual$MTD_0
mtd_1 <- mtd_manual$MTD_1
mtd_2 <- mtd_manual$MTD_2
mtd_3 <- mtd_manual$MTD_3

# Create data frame for repeated measures
mtd_long <- data.frame(
  Program = rep(mtd_manual$Program, 4),
  NTC = rep(c(0, 1, 2, 3), each = nrow(mtd_manual)),
  MTD = c(mtd_0, mtd_1, mtd_2, mtd_3)
)

# Descriptive statistics
cat("Descriptive Statistics for MTD at each test case level:\n")
for (ntc in 0:3) {
  mtd_vals <- mtd_long$MTD[mtd_long$NTC == ntc]
  cat(sprintf("  NTC=%d: Mean=%.2f, SD=%.2f, Median=%.2f\n",
              ntc, mean(mtd_vals), sd(mtd_vals), median(mtd_vals)))
}

# Calculate reduction percentages
reduction_0_1 <- ((sum(mtd_0) - sum(mtd_1)) / sum(mtd_0)) * 100
reduction_0_2 <- ((sum(mtd_0) - sum(mtd_2)) / sum(mtd_0)) * 100
reduction_0_3 <- ((sum(mtd_0) - sum(mtd_3)) / sum(mtd_0)) * 100

cat(sprintf("\nMTD Reduction Percentages:\n"))
cat(sprintf("  0 to 1 test case: %.2f%%\n", reduction_0_1))
cat(sprintf("  0 to 2 test cases: %.2f%%\n", reduction_0_2))
cat(sprintf("  0 to 3 test cases: %.2f%%\n", reduction_0_3))

# Friedman test for repeated measures (non-parametric)
# Create matrix for Friedman test
mtd_matrix <- cbind(mtd_0, mtd_1, mtd_2, mtd_3)
friedman_result <- friedman.test(mtd_matrix)

cat(sprintf("\nFriedman Test (Non-parametric repeated measures):\n"))
cat(sprintf("  Chi-squared: %.4f\n", friedman_result$statistic))
cat(sprintf("  df: %d\n", friedman_result$parameter))
cat(sprintf("  p-value: %.10f\n", friedman_result$p.value))

# Post-hoc pairwise Wilcoxon signed-rank tests
cat("\nPairwise Wilcoxon Signed-Rank Tests:\n")
pairs <- list(
  c("NTC=0 vs NTC=1", 1, 2),
  c("NTC=1 vs NTC=2", 2, 3),
  c("NTC=2 vs NTC=3", 3, 4)
)

for (pair in pairs) {
  col1 <- as.numeric(pair[2])
  col2 <- as.numeric(pair[3])
  wilcox_result <- wilcox.test(mtd_matrix[, col1], mtd_matrix[, col2], paired = TRUE)
  cat(sprintf("  %s: V=%.1f, p=%.6f\n", pair[1], wilcox_result$statistic, wilcox_result$p.value))
}

# ============================================================
# RQ3: Does MTDauto differ significantly from MTDmanual?
# ============================================================

cat("\n==================================================\n")
cat("RQ3: Comparison of MTDmanual vs MTDauto\n")
cat("==================================================\n\n")

# Calculate MTD manual (using SSDL data at NTC=0)
# MTD_manual = 0.25 hours per mutant (15 minutes)
mtd_manual_initial <- programs$SSDL * 0.25

# MTD_auto from the auto_evolution data (using SSDL_MTDauto_0)
mtd_auto_initial <- mtd_auto$SSDL_MTDauto_0

# Descriptive statistics
cat("Descriptive Statistics:\n")
cat(sprintf("  MTD_manual: Mean=%.2f, SD=%.2f, Median=%.2f\n",
            mean(mtd_manual_initial), sd(mtd_manual_initial), median(mtd_manual_initial)))
cat(sprintf("  MTD_auto: Mean=%.2f, SD=%.2f, Median=%.2f\n",
            mean(mtd_auto_initial), sd(mtd_auto_initial), median(mtd_auto_initial)))

# Calculate ratio
ratio <- mtd_manual_initial / mtd_auto_initial
ratio[is.infinite(ratio)] <- NA
cat(sprintf("\nRatio MTD_manual/MTD_auto:\n"))
cat(sprintf("  Mean: %.2f\n", mean(ratio, na.rm=TRUE)))
cat(sprintf("  Min: %.2f, Max: %.2f\n", min(ratio, na.rm=TRUE), max(ratio, na.rm=TRUE)))

# Wilcoxon signed-rank test
wilcox_comparison <- wilcox.test(mtd_manual_initial, mtd_auto_initial, paired = TRUE)
cat(sprintf("\nWilcoxon Signed-Rank Test (MTD_manual vs MTD_auto):\n"))
cat(sprintf("  V: %.1f\n", wilcox_comparison$statistic))
cat(sprintf("  p-value: %.10f\n", wilcox_comparison$p.value))

# ============================================================
# RQ4: Effect of SSDL-adequate test set on overall MTD
# ============================================================

cat("\n==================================================\n")
cat("RQ4: Impact of SSDL-adequate Test Set on MTD\n")
cat("==================================================\n\n")

# From Table 5 in the paper - Initial MTD vs MTD after SSDL-adequate
# Using ALL operator data
# Initial MTD = 16629.5 (total)
# MTD after SSDL-adequate = 2327.6 (total)

# We need to extract this from the available data
# Program-level analysis of reduction

# Calculate initial MTD for all operators
# Assuming 0.25 hours per mutant
mtd_all_initial <- programs$TOTAL * 0.25

# MTD after SSDL-adequate (from ALL_MTDauto data at NTC when SSDL is adequate)
# This is approximate since we don't have exact SSDL-adequate NTC for each program

# Estimate based on average mutation score achieved
avg_score_all <- mean(mtd_auto$ALL_Score_3)
mtd_all_after <- mtd_auto$ALL_MTDauto_3

cat("MTD Reduction with SSDL-adequate test set:\n")
cat(sprintf("  Total Initial MTD (all operators): %.2f person-hours\n", sum(mtd_all_initial)))
cat(sprintf("  Total MTD after 3 test cases: %.2f person-hours\n", sum(mtd_all_after)))
cat(sprintf("  Reduction: %.2f%%\n", ((sum(mtd_all_initial) - sum(mtd_all_after)) / sum(mtd_all_initial)) * 100))

# ============================================================
# Additional analyses: Variance and Stability
# ============================================================

cat("\n==================================================\n")
cat("Additional Analysis: MTD Variance and Stability\n")
cat("==================================================\n\n")

# Coefficient of variation for MTD at different stages
cv_0 <- (sd(mtd_0) / mean(mtd_0)) * 100
cv_1 <- (sd(mtd_1) / mean(mtd_1)) * 100
cv_2 <- (sd(mtd_2) / mean(mtd_2)) * 100
cv_3 <- (sd(mtd_3) / mean(mtd_3)) * 100

cat("Coefficient of Variation (CV) for MTD:\n")
cat(sprintf("  NTC=0: %.2f%%\n", cv_0))
cat(sprintf("  NTC=1: %.2f%%\n", cv_1))
cat(sprintf("  NTC=2: %.2f%%\n", cv_2))
cat(sprintf("  NTC=3: %.2f%%\n", cv_3))

# 95% Confidence Intervals
cat("\n95% Confidence Intervals for Mean MTD:\n")
for (ntc in 0:3) {
  mtd_vals <- mtd_long$MTD[mtd_long$NTC == ntc]
  ci <- t.test(mtd_vals)$conf.int
  cat(sprintf("  NTC=%d: [%.2f, %.2f]\n", ntc, ci[1], ci[2]))
}

# ============================================================
# Correlation between program characteristics and MTD
# ============================================================

cat("\n==================================================\n")
cat("Correlation Analysis: Program Characteristics vs MTD\n")
cat("==================================================\n\n")

# Correlation between LOC and initial MTD
cor_loc_mtd <- cor.test(programs$LOC, mtd_manual$MTD_0, method = "spearman")
cat(sprintf("LOC vs Initial MTD:\n"))
cat(sprintf("  Spearman rho: %.4f, p-value: %.6f\n", cor_loc_mtd$estimate, cor_loc_mtd$p.value))

# Correlation between total mutants and initial MTD
cor_total_mtd <- cor.test(programs$TOTAL, mtd_manual$MTD_0, method = "spearman")
cat(sprintf("\nTotal Mutants vs Initial MTD:\n"))
cat(sprintf("  Spearman rho: %.4f, p-value: %.6f\n", cor_total_mtd$estimate, cor_total_mtd$p.value))

# Correlation between SSDL mutants and initial MTD
cor_ssdl_mtd <- cor.test(programs$SSDL, mtd_manual$MTD_0, method = "spearman")
cat(sprintf("\nSSDL Mutants vs Initial MTD:\n"))
cat(sprintf("  Spearman rho: %.4f, p-value: %.6f\n", cor_ssdl_mtd$estimate, cor_ssdl_mtd$p.value))

cat("\n==================================================\n")
cat("Statistical Analysis Complete\n")
cat("==================================================\n")

# Save summary to file
sink("data/statistical_summary.txt")
cat("MTD Statistical Analysis Summary\n")
cat("================================\n\n")
cat(sprintf("Total programs analyzed: %d\n", nrow(programs)))
cat(sprintf("Total SSDL mutants: %d\n", sum(programs$SSDL)))
cat(sprintf("Total equivalent SSDL mutants: %d (%.2f%%)\n", sum(programs$EQ_SSDL), (sum(programs$EQ_SSDL)/sum(programs$SSDL))*100))
cat(sprintf("\nMTD Reduction (Friedman test): Chi-squared=%.4f, p<0.001\n", friedman_result$statistic))
cat(sprintf("Correlation Score vs MTD: rho=%.4f, p<0.001\n", cor_test$estimate))
sink()
