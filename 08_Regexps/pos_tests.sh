#!/bin/bash

curr_dir=$1

echo 'qwe(ab)sdqqq((ads))d123' | sed -E 's/([a-c])([d])/--\0--/' > ${curr_dir}/testing/helper.txt
./esub '([a-c])([d])' '--\0--' 'qwe(ab)sdqqq((ads))d123' > ${curr_dir}/testing/tmp_test_custom.txt
cmp ${curr_dir}/testing/tmp_test_custom.txt ${curr_dir}/testing/helper.txt

if [[ $? != "0" ]]; then
    exit "1"
fi

echo 'qwe(ab)sdqqq((ads))d123' | sed -E 's/([a-c])([d])/--\1--/' > ${curr_dir}/testing/helper.txt
./esub '([a-c])([d])' '--\1--' 'qwe(ab)sdqqq((ads))d123' > ${curr_dir}/testing/tmp_test_custom.txt
cmp ${curr_dir}/testing/tmp_test_custom.txt ${curr_dir}/testing/helper.txt

if [[ $? != "0" ]]; then
    exit "1"
fi

echo 'qwe(ab)sdqqq((ads))d123' | sed -E 's/([a-c])([d])/--\2--/' > ${curr_dir}/testing/helper.txt
./esub '([a-c])([d])' '--\2--' 'qwe(ab)sdqqq((ads))d123' > ${curr_dir}/testing/tmp_test_custom.txt
cmp ${curr_dir}/testing/tmp_test_custom.txt ${curr_dir}/testing/helper.txt

if [[ $? != "0" ]]; then
    exit "1"
fi

echo 'qwe(ab)sdqqq((ads))d123' | sed -E 's/([a-c])([d])/--\--/' > ${curr_dir}/testing/helper.txt
./esub '([a-c])([d])' '--\--' 'qwe(ab)sdqqq((ads))d123' > ${curr_dir}/testing/tmp_test_custom.txt
cmp ${curr_dir}/testing/tmp_test_custom.txt ${curr_dir}/testing/helper.txt

if [[ $? != "0" ]]; then
    exit "1"
fi

echo 'qwe(ab)sdqqq((ads))d123' | sed -E 's/([a-c])([d])/--\\--/' > ${curr_dir}/testing/helper.txt
./esub '([a-c])([d])' '--\\--' 'qwe(ab)sdqqq((ads))d123' > ${curr_dir}/testing/tmp_test_custom.txt
cmp ${curr_dir}/testing/tmp_test_custom.txt ${curr_dir}/testing/helper.txt

if [[ $? != "0" ]]; then
    exit "1"
fi

echo 'qwe(ab)sdqqq((ads))d123' | sed -E 's/([a-c])([d])/--\\\--/' > ${curr_dir}/testing/helper.txt
./esub '([a-c])([d])' '--\\\--' 'qwe(ab)sdqqq((ads))d123' > ${curr_dir}/testing/tmp_test_custom.txt
cmp ${curr_dir}/testing/tmp_test_custom.txt ${curr_dir}/testing/helper.txt

if [[ $? != "0" ]]; then
    exit "1"
fi

echo 'qwe(ab)sdqqq((ads))d123' | sed -E 's/([a-c])([d])/--\\\\--/' > ${curr_dir}/testing/helper.txt
./esub '([a-c])([d])' '--\\\\--' 'qwe(ab)sdqqq((ads))d123' > ${curr_dir}/testing/tmp_test_custom.txt
cmp ${curr_dir}/testing/tmp_test_custom.txt ${curr_dir}/testing/helper.txt

if [[ $? != "0" ]]; then
    exit "1"
fi

echo 'qwe(ab)sdqqq((ads))d123' | sed -E 's/([a-c])([d])/--\\\\\--/' > ${curr_dir}/testing/helper.txt
./esub '([a-c])([d])' '--\\\\\--' 'qwe(ab)sdqqq((ads))d123' > ${curr_dir}/testing/tmp_test_custom.txt
cmp ${curr_dir}/testing/tmp_test_custom.txt ${curr_dir}/testing/helper.txt

if [[ $? != "0" ]]; then
    exit "1"
fi

echo 'qwe(ab)sdqqq((ads))d123' | sed -E 's/([a-c])([d])/--\\\\\\--/' > ${curr_dir}/testing/helper.txt
./esub '([a-c])([d])' '--\\\\\\--' 'qwe(ab)sdqqq((ads))d123' > ${curr_dir}/testing/tmp_test_custom.txt
cmp ${curr_dir}/testing/tmp_test_custom.txt ${curr_dir}/testing/helper.txt

if [[ $? != "0" ]]; then
    exit "1"
fi