# QualityFilter
# Language: C++
# Input: QZA
# Output: PREFIX
# Tested with: PluMA 1.1, GCC 4.8.4
# Dependency: Qiime 2 2020.11, Conda 4.9.2

Qiime2 quality filtering (Bolyen et al, 2019).

The plugin accepts as input a QZA file of paired-end sequences.

It will output two files, using the user-specified output prefix:

prefix-demux-filtered.qza: Filtered sequences
prefix-demux-filter-stats.qza: Statistics


