#!/usr/bin/env python3

import os
import sys

UNITTEST = {
    # nom du fichier : [format , value1, value2, ... ],

     "simple_test": ["simple"],
    "test_int_zero_01": ["%d]", 0],
	"test_int_zero_02": ["%0.0d]", 0],
	"test_int_zero_03": ["%.0d]", 0],
	"test_int_zero_04": ["%25d]", 0],
	"test_int_zero_05": ["%025.0d]", 0],
	"test_int_zero_06": ["%25.0d]", 0],
	"test_int_zero_07": ["%-25.0d]", 0],
    "test_int_zero_08": ["%-5.0d]", 0],
	"test_int_zero_09": ["%.5d]", 0],
	"test_int_zero_10": ["%-5.5d]", 0],
	"test_int_zero_11": ["%0.25d]", 0],
	"test_int_zero_12": ["%.25d]", 0],
	"test_int_zero_13": ["%-5.25d]", 0],
	"test_int_zero_14": ["%025.25d]", 0],
	"test_int_zero_15": ["%25.25d]", 0],
	"test_int_zero_16": ["%025.25d]", 0],
    "test_int_zero_17": ["%25.25d]", 0],
	"test_int_zero_18": ["%-25.25d]", 0],
	"test_int_zero_19": ["%5d]", 0],
	"test_int_zero_20": ["%05.0d]", 0],
	"test_int_zero_21": ["%5.0d]", 0],
	"test_int_zero_22": ["%05.5d]", 0],
	"test_int_zero_23": ["%5.5d]", 0],
	"test_int_zero_24": ["%.25d]", 0],
	"test_int_zero_24": ["%25d]", 0],
	"test_int_zero_25": ["%025d]", 0],
	"test_int_zero_26": ["%.*d]", 0, 0],
	"test_int_zero_27": ["%.*d]", 25, 0],
	"test_int_zero_28": ["%.*d]", -25, 0],
	"test_int_zero_29": ["%*d]", 25, 0],
	"test_int_zero_30": ["%*d]", -25, 0],
	"test_int_zero_31": ["%25.*d]", 25, 0],
	"test_int_zero_32": ["%25.*d]", -25, 0],
	"test_int_zero_33": ["%-25.*d]", -25, 0],
	"test_int_zero_34": ["%-25.*d]", 25, 0],
	"test_int_zero_35": ["%025.*d]", -25, 0],
	"test_int_zero_36": ["%025.*d]", 25, 0],
	"test_int_zero_37": ["%*.0d]", -25, 0],
	"test_int_zero_38": ["%*.0d]", 25, 0],
	"test_int_zero_39": ["%*.25d]", -25, 0],
	"test_int_zero_40": ["%*.25d]", 25, 0],
	"test_int_zero_41": ["%-*.25d]", -25, 0],
	"test_int_zero_42": ["%-*.25d]", 25, 0],
	"test_int_zero_43": ["%0*.25d]", -25, 0],
	"test_int_zero_44": ["%0*.25d]", 25, 0],
	"test_int_zero_45": ["%-*.*d]", -25, 25, 0],
	"test_int_zero_46": ["%-*.*d]", 25, -25, 0],
	"test_int_zero_47": ["%-*.*d]", 25, 25, 0],
	"test_int_zero_48": ["%-*.*d]", -25, -25, 0],
	"test_int_zero_49": ["%*.*d]", 0, -25, 0],
	"test_int_zero_50": ["%*.*d]", 0, 25, 0],
	"test_int_zero_51": ["%*.*d]", 0, 0, 0],
	"test_int_zero_52": ["%*.*d]", -25, 0, 0],
	"test_int_zero_53": ["%*.*d]", 25, 0, 0],
	"test_int_zero_54": ["%0*.*d]", 25, 0, 0],
	"test_int_zero_55": ["%0*.*d]", 0, 25, 0],
	"test_int_zero_56": ["%0*.*d]", 0, -25, 0],
	"test_int_zero_57": ["%0*.*d]", -25, 0, 0],
	"test_int_zero_58": ["%0*.*d]", 0, 0, 0],
	"test_int_zero_59": ["%-*.*d]", 0, 0, 0],
	"test_int_zero_60": ["%-*.*d]", 25, 0, 0],
	"test_int_zero_61": ["%-*.*d]", 0, 25, 0],
	"test_int_zero_62": ["%-*.*d]", 0, -25, 0],
	"test_int_zero_63": ["%-*.*d]", -25, 0, 0],
	"test_int_zero_64": ["%-*.*d]", 0, 0, 0],
    "test_int_pos_01": ["%0d]", 2147483647],
	"test_int_pos_02": ["%0.0d]", 2147483647],
	"test_int_pos_03": ["%.0d]", 2147483647],
	"test_int_pos_04": ["%25d]", 2147483647],
	"test_int_pos_05": ["%025.0d]", 2147483647],
	"test_int_pos_06": ["%25.0d]", 2147483647],
	"test_int_pos_07": ["%-25.0d]", 2147483647],
    "test_int_pos_08": ["%-5.0d]", 2147483647],
	"test_int_pos_09": ["%.5d]", 2147483647],
	"test_int_pos_10": ["%-5.5d]", 2147483647],
	"test_int_pos_11": ["%0.25d]", 2147483647],
	"test_int_pos_12": ["%.25d]", 2147483647],
	"test_int_pos_13": ["%-5.25d]", 2147483647],
	"test_int_pos_14": ["%025.25d]", 2147483647],
    "test_int_pos_15": ["%25.25d]", 2147483647],
	"test_int_pos_16": ["%-25.25d]", 2147483647],
	"test_int_pos_17": ["%5d]", 2147483647],
	"test_int_pos_18": ["%05.0d]", 2147483647],
	"test_int_pos_19": ["%5.0d]", 2147483647],
	"test_int_pos_20": ["%05.5d]", 2147483647],
	"test_int_pos_22": ["%5.5d]", 2147483647],
	"test_int_pos_23": ["%.25d]", 2147483647],
	"test_int_pos_24": ["%25d]", 2147483647],
	"test_int_pos_25": ["%025d]", 2147483647],
	"test_int_pos_26": ["%.*d]", 0, 2147483647],
	"test_int_pos_27": ["%.*d]", 25, 2147483647],
	"test_int_pos_28": ["%.*d]", -25, 2147483647],
	"test_int_pos_29": ["%*d]", 25, 2147483647],
	"test_int_pos_30": ["%*d]", -25, 2147483647],
	"test_int_pos_31": ["%25.*d]", 25, 2147483647],
	"test_int_pos_32": ["%25.*d]", -25, 2147483647],
	"test_int_pos_33": ["%-25.*d]", -25, 2147483647],
	"test_int_pos_34": ["%-25.*d]", 25, 2147483647],
	"test_int_pos_35": ["%025.*d]", -25, 2147483647],
	"test_int_pos_36": ["%025.*d]", 25, 2147483647],
	"test_int_pos_37": ["%*.0d]", -25, 2147483647],
	"test_int_pos_38": ["%*.0d]", 25, 2147483647],
	"test_int_pos_39": ["%*.25d]", -25, 2147483647],
	"test_int_pos_40": ["%*.25d]", 25, 2147483647],
	"test_int_pos_41": ["%-*.25d]", -25, 2147483647],
	"test_int_pos_42": ["%-*.25d]", 25, 2147483647],
	"test_int_pos_43": ["%0*.25d]", -25, 2147483647],
	"test_int_pos_44": ["%0*.25d]", 25, 2147483647],
	"test_int_pos_45": ["%-*.*d]", -25, 25, 2147483647],
	"test_int_pos_46": ["%-*.*d]", 25, -25, 2147483647],
	"test_int_pos_47": ["%-*.*d]", 25, 25, 2147483647],
	"test_int_pos_48": ["%-*.*d]", -25, -25, 2147483647],
	"test_int_pos_49": ["%*.*d]", 0, -25, 2147483647],
	"test_int_pos_50": ["%*.*d]", 0, 25, 2147483647],
	"test_int_pos_51": ["%*.*d]", 0, 0, 2147483647],
	"test_int_pos_52": ["%*.*d]", -25, 0, 2147483647],
	"test_int_pos_53": ["%*.*d]", 25, 0, 2147483647],
	"test_int_pos_54": ["%0*.*d]", 25, 0, 2147483647],
	"test_int_pos_55": ["%0*.*d]", 0, 25, 2147483647],
	"test_int_pos_56": ["%0*.*d]", 0, -25, 2147483647],
	"test_int_pos_57": ["%0*.*d]", -25, 0, 2147483647],
	"test_int_pos_58": ["%0*.*d]", 0, 0, 2147483647],
	"test_int_pos_59": ["%-*.*d]", 0, 0, 2147483647],
	"test_int_pos_60": ["%-*.*d]", 25, 0, 2147483647],
	"test_int_pos_61": ["%-*.*d]", 0, 25, 2147483647],
	"test_int_pos_62": ["%-*.*d]", 0, -25, 2147483647],
	"test_int_pos_63": ["%-*.*d]", -25, 0, 2147483647],
	"test_int_pos_64": ["%-*.*d]", 0, 0, 2147483647],
    "test_int_neg_01": ["%0d]", -2147483647],
	"test_int_neg_02": ["%0.0d]", -2147483647],
	"test_int_neg_03": ["%.0d]", -2147483647],
	"test_int_neg_04": ["%25d]", -2147483647],
	"test_int_neg_05": ["%025.0d]", -2147483647],
	"test_int_neg_06": ["%25.0d]", -2147483647],
	"test_int_neg_07": ["%-25.0d]", -2147483647],
    "test_int_neg_08": ["%-5.0d]", -2147483647],
	"test_int_neg_09": ["%.5d]", -2147483647],
	"test_int_neg_10": ["%-5.5d]", -2147483647],
	"test_int_neg_11": ["%0.25d]", -2147483647],
	"test_int_neg_12": ["%.25d]", -2147483647],
	"test_int_neg_13": ["%-5.25d]", -2147483647],
	"test_int_neg_14": ["%025.25d]", -2147483647],
    "test_int_neg_15": ["%25.25d]", -2147483647],
	"test_int_neg_16": ["%-25.25d]", -2147483647],
	"test_int_neg_17": ["%5d]", -2147483647],
	"test_int_neg_18": ["%05.0d]", -2147483647],
	"test_int_neg_19": ["%5.0d]", -2147483647],
	"test_int_neg_20": ["%05.5d]", -2147483647],
	"test_int_neg_22": ["%5.5d]", -2147483647],
	"test_int_neg_23": ["%.25d]", -2147483647],
	"test_int_neg_24": ["%25d]", -2147483647],
	"test_int_neg_25": ["%025d]", -2147483647],
	"test_int_neg_26": ["%.*d]", 0, -2147483647],
	"test_int_neg_27": ["%.*d]", 25, -2147483647],
	"test_int_neg_28": ["%.*d]", -25, -2147483647],
	"test_int_neg_29": ["%*d]", 25, -2147483647],
	"test_int_neg_30": ["%*d]", -25, -2147483647],
	"test_int_neg_31": ["%25.*d]", 25, -2147483647],
	"test_int_neg_32": ["%25.*d]", -25, -2147483647],
	"test_int_neg_33": ["%-25.*d]", -25, -2147483647],
	"test_int_neg_34": ["%-25.*d]", 25, -2147483647],
	"test_int_neg_35": ["%025.*d]", -25, -2147483647],
	"test_int_neg_36": ["%025.*d]", 25, -2147483647],
	"test_int_neg_37": ["%*.0d]", -25, -2147483647],
	"test_int_neg_38": ["%*.0d]", 25, -2147483647],
	"test_int_neg_39": ["%*.25d]", -25, -2147483647],
	"test_int_neg_40": ["%*.25d]", 25, -2147483647],
	"test_int_neg_41": ["%-*.25d]", -25, -2147483647],
	"test_int_neg_42": ["%-*.25d]", 25, -2147483647],
	"test_int_neg_43": ["%0*.25d]", -25, -2147483647],
	"test_int_neg_44": ["%0*.25d]", 25, -2147483647],
	"test_int_neg_45": ["%-*.*d]", -25, 25, -2147483647],
	"test_int_neg_46": ["%-*.*d]", 25, -25, -2147483647],
	"test_int_neg_47": ["%-*.*d]", 25, 25, -2147483647],
	"test_int_neg_48": ["%-*.*d]", -25, -25, -2147483647],
	"test_int_neg_49": ["%*.*d]", 0, -25, -2147483647],
	"test_int_neg_50": ["%*.*d]", 0, 25, -2147483647],
	"test_int_neg_51": ["%*.*d]", 0, 0, -2147483647],
	"test_int_neg_52": ["%*.*d]", -25, 0, -2147483647],
	"test_int_neg_53": ["%*.*d]", 25, 0, -2147483647],
	"test_int_neg_54": ["%0*.*d]", 25, 0, -2147483647],
	"test_int_neg_55": ["%0*.*d]", 0, 25, -2147483647],
	"test_int_neg_56": ["%0*.*d]", 0, -25, -2147483647],
	"test_int_neg_57": ["%0*.*d]", -25, 0, -2147483647],
	"test_int_neg_58": ["%0*.*d]", 0, 0, -2147483647],
	"test_int_neg_59": ["%-*.*d]", 0, 0, -2147483647],
	"test_int_neg_60": ["%-*.*d]", 25, 0, -2147483647],
	"test_int_neg_61": ["%-*.*d]", 0, 25, -2147483647],
	"test_int_neg_62": ["%-*.*d]", 0, -25, -2147483647],
	"test_int_neg_63": ["%-*.*d]", -25, 0, -2147483647],
	"test_int_neg_64": ["%-*.*d]", 0, 0, -2147483647],
    "test_u_zero": ["%u]", 0],
    "test_u_neg_01": ["%0u]", -2147483647],
	"test_u_neg_02": ["%0.0u]", -2147483647],
	"test_u_neg_03": ["%.0u]", -2147483647],
	"test_u_neg_04": ["%25u]", -2147483647],
	"test_u_neg_05": ["%025.0u]", -2147483647],
	"test_u_neg_06": ["%25.0u]", -2147483647],
	"test_u_neg_07": ["%-25.0u]", -2147483647],
    "test_u_neg_08": ["%-5.0u]", -2147483647],
	"test_u_neg_09": ["%.5u]", -2147483647],
	"test_u_neg_10": ["%-5.5u]", -2147483647],
	"test_u_neg_11": ["%0.25u]", -2147483647],
	"test_u_neg_12": ["%.25u]", -2147483647],
	"test_u_neg_13": ["%-5.25u]", -2147483647],
	"test_u_neg_14": ["%025.25u]", -2147483647],
    "test_u_neg_15": ["%25.25u]", -2147483647],
	"test_u_neg_16": ["%-25.25u]", -2147483647],
	"test_u_neg_17": ["%5u]", -2147483647],
	"test_u_neg_18": ["%05.0u]", -2147483647],
	"test_u_neg_19": ["%5.0u]", -2147483647],
	"test_u_neg_20": ["%05.5u]", -2147483647],
	"test_u_neg_22": ["%5.5u]", -2147483647],
	"test_u_neg_23": ["%.25u]", -2147483647],
	"test_u_neg_24": ["%25u]", 2147483647],
	"test_u_neg_25": ["%025u]", 2147483647],
	"test_u_neg_26": ["%.*u]", 0, -2147483647],
	"test_u_neg_27": ["%.*u]", 25, -2147483647],
	"test_u_neg_28": ["%.*u]", -25, -2147483647],
	"test_u_neg_29": ["%*u]", 25, -2147483647],
	"test_u_neg_30": ["%*u]", -25, -2147483647],
	"test_u_neg_31": ["%25.*u]", 25, -2147483647],
	"test_u_neg_32": ["%25.*u]", -25, -2147483647],
	"test_u_neg_33": ["%-25.*u]", -25, -2147483647],
	"test_u_neg_34": ["%-25.*u]", 25, -2147483647],
	"test_u_neg_35": ["%025.*u]", -25, -2147483647],
	"test_u_neg_36": ["%025.*u]", 25, -2147483647],
	"test_u_neg_37": ["%*.0u]", -25, -2147483647],
	"test_u_neg_38": ["%*.0u]", 25, -2147483647],
	"test_u_neg_39": ["%*.25u]", -25, -2147483647],
	"test_u_neg_40": ["%*.25u]", 25, -2147483647],
	"test_u_neg_41": ["%-*.25u]", -25, -2147483647],
	"test_u_neg_42": ["%-*.25u]", 25, -2147483647],
	"test_u_neg_43": ["%0*.25u]", -25, -2147483647],
	"test_u_neg_44": ["%0*.25u]", 25, -2147483647],
	"test_u_neg_45": ["%-*.*u]", -25, 25, -2147483647],
	"test_u_neg_46": ["%-*.*u]", 25, -25, -2147483647],
	"test_u_neg_47": ["%-*.*u]", 25, 25, -2147483647],
	"test_u_neg_48": ["%-*.*u]", -25, -25, -2147483647],
	"test_u_neg_49": ["%*.*u]", 0, -25, -2147483647],
	"test_u_neg_50": ["%*.*u]", 0, 25, -2147483647],
	"test_u_neg_51": ["%*.*u]", 0, 0, -2147483647],
	"test_u_neg_52": ["%*.*u]", -25, 0, -2147483647],
	"test_u_neg_53": ["%*.*u]", 25, 0, -2147483647],
	"test_u_neg_54": ["%0*.*u]", 25, 0, -2147483647],
	"test_u_neg_55": ["%0*.*u]", 0, 25, -2147483647],
	"test_u_neg_56": ["%0*.*u]", 0, -25, -2147483647],
	"test_u_neg_57": ["%0*.*u]", -25, 0, -2147483647],
	"test_u_neg_58": ["%0*.*u]", 0, 0, -2147483647],
	"test_u_neg_59": ["%-*.*u]", 0, 0, -2147483647],
	"test_u_neg_60": ["%-*.*u]", 25, 0, -2147483647],
	"test_u_neg_61": ["%-*.*u]", 0, 25, -2147483647],
	"test_u_neg_62": ["%-*.*u]", 0, -25, -2147483647],
	"test_u_neg_63": ["%-*.*u]", -25, 0, -2147483647],
	"test_u_neg_64": ["%-*.*u]", 0, 0, -2147483647],
    "test_u_pos_01": ["%0u]", 2147483647],
	"test_u_pos_02": ["%0.0u]", 2147483647],
	"test_u_pos_03": ["%.0u]", 2147483647],
	"test_u_pos_04": ["%25u]", 2147483647],
	"test_u_pos_05": ["%025.0u]", 2147483647],
	"test_u_pos_06": ["%25.0u]", 2147483647],
	"test_u_pos_07": ["%-25.0u]", 2147483647],
    "test_u_pos_08": ["%-5.0u]", 2147483647],
	"test_u_pos_09": ["%.5u]", 2147483647],
	"test_u_pos_10": ["%-5.5u]", 2147483647],
	"test_u_pos_11": ["%0.25u]", 2147483647],
	"test_u_pos_12": ["%.25u]", 2147483647],
	"test_u_pos_13": ["%-5.25u]", 2147483647],
	"test_u_pos_14": ["%025.25u]", 2147483647],
    "test_u_pos_15": ["%25.25u]", 2147483647],
	"test_u_pos_16": ["%-25.25u]", 2147483647],
	"test_u_pos_17": ["%5u]", 2147483647],
	"test_u_pos_18": ["%05.0u]", 2147483647],
	"test_u_pos_19": ["%5.0u]", 2147483647],
	"test_u_pos_20": ["%05.5u]", 2147483647],
	"test_u_pos_22": ["%5.5u]", 2147483647],
	"test_u_pos_23": ["%.25u]", 2147483647],
	"test_u_pos_24": ["%25u]", 2147483647],
	"test_u_pos_25": ["%025u]", 2147483647],
	"test_u_pos_26": ["%.*u]", 0, 2147483647],
	"test_u_pos_27": ["%.*u]", 25, 2147483647],
	"test_u_pos_28": ["%.*u]", -25, 2147483647],
	"test_u_pos_29": ["%*u]", 25, 2147483647],
	"test_u_pos_30": ["%*u]", -25, 2147483647],
	"test_u_pos_31": ["%25.*u]", 25, 2147483647],
	"test_u_pos_32": ["%25.*u]", -25, 2147483647],
	"test_u_pos_33": ["%-25.*u]", -25, 2147483647],
	"test_u_pos_34": ["%-25.*u]", 25, 2147483647],
	"test_u_pos_35": ["%025.*u]", -25, 2147483647],
	"test_u_pos_36": ["%025.*u]", 25, 2147483647],
	"test_u_pos_37": ["%*.0u]", -25, 2147483647],
	"test_u_pos_38": ["%*.0u]", 25, 2147483647],
	"test_u_pos_39": ["%*.25u]", -25, 2147483647],
	"test_u_pos_40": ["%*.25u]", 25, 2147483647],
	"test_u_pos_41": ["%-*.25u]", -25, 2147483647],
	"test_u_pos_42": ["%-*.25u]", 25, 2147483647],
	"test_u_pos_43": ["%0*.25u]", -25, 2147483647],
	"test_u_pos_44": ["%0*.25u]", 25, 2147483647],
	"test_u_pos_45": ["%-*.*u]", -25, 25, 2147483647],
	"test_u_pos_46": ["%-*.*u]", 25, -25, 2147483647],
	"test_u_pos_47": ["%-*.*u]", 25, 25, 2147483647],
	"test_u_pos_48": ["%-*.*u]", -25, -25, 2147483647],
	"test_u_pos_49": ["%*.*u]", 0, -25, 2147483647],
	"test_u_pos_50": ["%*.*u]", 0, 25, 2147483647],
	"test_u_pos_51": ["%*.*u]", 0, 0, 2147483647],
	"test_u_pos_52": ["%*.*u]", -25, 0, 2147483647],
	"test_u_pos_53": ["%*.*u]", 25, 0, 2147483647],
	"test_u_pos_54": ["%0*.*u]", 25, 0, 2147483647],
	"test_u_pos_55": ["%0*.*u]", 0, 25, 2147483647],
	"test_u_pos_56": ["%0*.*u]", 0, -25, 2147483647],
	"test_u_pos_57": ["%0*.*u]", -25, 0, 2147483647],
	"test_u_pos_58": ["%0*.*u]", 0, 0, 2147483647],
	"test_u_pos_59": ["%-*.*u]", 0, 0, 2147483647],
	"test_u_pos_60": ["%-*.*u]", 25, 0, 2147483647],
	"test_u_pos_61": ["%-*.*u]", 0, 25, 2147483647],
	"test_u_pos_62": ["%-*.*u]", 0, -25, 2147483647],
	"test_u_pos_63": ["%-*.*u]", -25, 0, 2147483647],
	"test_u_pos_64": ["%-*.*u]", 0, 0, 2147483647],
    "test_x_zero": ["%u]", 0],
	"test_x_neg_01": ["%0x]", -2147483647],
	"test_x_neg_02": ["%0.0x]", -2147483647],
	"test_x_neg_03": ["%.0x]", -2147483647],
	"test_x_neg_04": ["%25x]", -2147483647],
	"test_x_neg_05": ["%025.0x]", -2147483647],
	"test_x_neg_06": ["%25.0x]", -2147483647],
	"test_x_neg_07": ["%-25.0x]", -2147483647],
    "test_x_neg_08": ["%-5.0x]", -2147483647],
	"test_x_neg_09": ["%.5x]", -2147483647],
	"test_x_neg_10": ["%-5.5x]", -2147483647],
	"test_x_neg_11": ["%0.25x]", -2147483647],
	"test_x_neg_12": ["%.25x]", -2147483647],
	"test_x_neg_13": ["%-5.25x]", -2147483647],
	"test_x_neg_14": ["%025.25x]", -2147483647],
    "test_x_neg_15": ["%25.25x]", -2147483647],
	"test_x_neg_16": ["%-25.25x]", -2147483647],
	"test_x_neg_17": ["%5x]", -2147483647],
	"test_x_neg_18": ["%05.0x]", -2147483647],
	"test_x_neg_19": ["%5.0x]", -2147483647],
	"test_x_neg_20": ["%05.5x]", -2147483647],
	"test_x_neg_22": ["%5.5x]", -2147483647],
	"test_x_neg_23": ["%.25x]", -2147483647],
	"test_x_neg_24": ["%25u]", -2147483647],
	"test_x_neg_25": ["%025x]", -2147483647],
	"test_x_neg_26": ["%.*x]", 0, -2147483647],
	"test_x_neg_27": ["%.*x]", 25, -2147483647],
	"test_x_neg_28": ["%.*x]", -25, -2147483647],
	"test_x_neg_29": ["%*x]", 25, -2147483647],
	"test_x_neg_30": ["%*x]", -25, -2147483647],
	"test_x_neg_31": ["%25.*x]", 25, -2147483647],
	"test_x_neg_32": ["%25.*x]", -25, -2147483647],
	"test_x_neg_33": ["%-25.*x]", -25, -2147483647],
	"test_x_neg_34": ["%-25.*x]", 25, -2147483647],
	"test_x_neg_35": ["%025.*x]", -25, -2147483647],
	"test_x_neg_36": ["%025.*x]", 25, -2147483647],
	"test_x_neg_37": ["%*.0x]", -25, -2147483647],
	"test_x_neg_38": ["%*.0x]", 25, -2147483647],
	"test_x_neg_39": ["%*.25x]", -25, -2147483647],
	"test_x_neg_40": ["%*.25x]", 25, -2147483647],
	"test_x_neg_41": ["%-*.25x]", -25, -2147483647],
	"test_x_neg_42": ["%-*.25x]", 25, -2147483647],
	"test_x_neg_43": ["%0*.25x]", -25, -2147483647],
	"test_x_neg_44": ["%0*.25x]", 25, -2147483647],
	"test_x_neg_45": ["%-*.*x]", -25, 25, -2147483647],
	"test_x_neg_46": ["%-*.*x]", 25, -25, -2147483647],
	"test_x_neg_47": ["%-*.*x]", 25, 25, -2147483647],
	"test_x_neg_48": ["%-*.*x]", -25, -25, -2147483647],
	"test_x_neg_49": ["%*.*x]", 0, -25, -2147483647],
	"test_x_neg_50": ["%*.*x]", 0, 25, -2147483647],
	"test_x_neg_51": ["%*.*x]", 0, 0, -2147483647],
	"test_x_neg_52": ["%*.*x]", -25, 0, -2147483647],
	"test_x_neg_53": ["%*.*x]", 25, 0, -2147483647],
	"test_x_neg_54": ["%0*.*x]", 25, 0, -2147483647],
	"test_x_neg_55": ["%0*.*x]", 0, 25, -2147483647],
	"test_x_neg_56": ["%0*.*x]", 0, -25, -2147483647],
	"test_x_neg_57": ["%0*.*x]", -25, 0, -2147483647],
	"test_x_neg_58": ["%0*.*x]", 0, 0, -2147483647],
	"test_x_neg_59": ["%-*.*x]", 0, 0, -2147483647],
	"test_x_neg_60": ["%-*.*x]", 25, 0, -2147483647],
	"test_x_neg_61": ["%-*.*x]", 0, 25, -2147483647],
	"test_x_neg_62": ["%-*.*x]", 0, -25, -2147483647],
	"test_x_neg_63": ["%-*.*x]", -25, 0, -2147483647],
	"test_x_neg_64": ["%-*.*x]", 0, 0, -2147483647],
    "test_x_pos_01": ["%0x]", 2147483647],
	"test_x_pos_02": ["%0.0x]", 2147483647],
	"test_x_pos_03": ["%.0x]", 2147483647],
	"test_x_pos_04": ["%25x]", 2147483647],
	"test_x_pos_05": ["%025.0x]", 2147483647],
	"test_x_pos_06": ["%25.0x]", 2147483647],
	"test_x_pos_07": ["%-25.0x]", 2147483647],
    "test_x_pos_08": ["%-5.0x]", 2147483647],
	"test_x_pos_09": ["%.5x]", 2147483647],
	"test_x_pos_10": ["%-5.5x]", 2147483647],
	"test_x_pos_11": ["%0.25x]", 2147483647],
	"test_x_pos_12": ["%.25x]", 2147483647],
	"test_x_pos_13": ["%-5.25x]", 2147483647],
	"test_x_pos_14": ["%025.25x]", 2147483647],
    "test_x_pos_15": ["%25.25x]", 2147483647],
	"test_x_pos_16": ["%-25.25x]", 2147483647],
	"test_x_pos_17": ["%5x]", 2147483647],
	"test_x_pos_18": ["%05.0x]", 2147483647],
	"test_x_pos_19": ["%5.0x]", 2147483647],
	"test_x_pos_20": ["%05.5x]", 2147483647],
	"test_x_pos_22": ["%5.5x]", 2147483647],
	"test_x_pos_23": ["%.25x]", 2147483647],
	"test_x_pos_24": ["%25x]", 2147483647],
	"test_x_pos_25": ["%025x]", 2147483647],
	"test_x_pos_26": ["%.*x]", 0, 2147483647],
	"test_x_pos_27": ["%.*x]", 25, 2147483647],
	"test_x_pos_28": ["%.*x]", -25, 2147483647],
	"test_x_pos_29": ["%*x]", 25, 2147483647],
	"test_x_pos_30": ["%*x]", -25, 2147483647],
	"test_x_pos_31": ["%25.*x]", 25, 2147483647],
	"test_x_pos_32": ["%25.*x]", -25, 2147483647],
	"test_x_pos_33": ["%-25.*x]", -25, 2147483647],
	"test_x_pos_34": ["%-25.*x]", 25, 2147483647],
	"test_x_pos_35": ["%025.*x]", -25, 2147483647],
	"test_x_pos_36": ["%025.*x]", 25, 2147483647],
	"test_x_pos_37": ["%*.0x]", -25, 2147483647],
	"test_x_pos_38": ["%*.0x]", 25, 2147483647],
	"test_x_pos_39": ["%*.25x]", -25, 2147483647],
	"test_x_pos_40": ["%*.25x]", 25, 2147483647],
	"test_x_pos_41": ["%-*.25x]", -25, 2147483647],
	"test_x_pos_42": ["%-*.25x]", 25, 2147483647],
	"test_x_pos_43": ["%0*.25x]", -25, 2147483647],
	"test_x_pos_44": ["%0*.25x]", 25, 2147483647],
	"test_x_pos_45": ["%-*.*x]", -25, 25, 2147483647],
	"test_x_pos_46": ["%-*.*x]", 25, -25, 2147483647],
	"test_x_pos_47": ["%-*.*x]", 25, 25, 2147483647],
	"test_x_pos_48": ["%-*.*x]", -25, -25, 2147483647],
	"test_x_pos_49": ["%*.*x]", 0, -25, 2147483647],
	"test_x_pos_50": ["%*.*x]", 0, 25, 2147483647],
	"test_x_pos_51": ["%*.*x]", 0, 0, 2147483647],
	"test_x_pos_52": ["%*.*x]", -25, 0, 2147483647],
	"test_x_pos_53": ["%*.*x]", 25, 0, 2147483647],
	"test_x_pos_54": ["%0*.*x]", 25, 0, 2147483647],
	"test_x_pos_55": ["%0*.*x]", 0, 25, 2147483647],
	"test_x_pos_56": ["%0*.*x]", 0, -25, 2147483647],
	"test_x_pos_57": ["%0*.*x]", -25, 0, 2147483647],
	"test_x_pos_58": ["%0*.*x]", 0, 0, 2147483647],
	"test_x_pos_59": ["%-*.*x]", 0, 0, 2147483647],
	"test_x_pos_60": ["%-*.*x]", 25, 0, 2147483647],
	"test_x_pos_61": ["%-*.*x]", 0, 25, 2147483647],
	"test_x_pos_62": ["%-*.*x]", 0, -25, 2147483647],
	"test_x_pos_63": ["%-*.*x]", -25, 0, 2147483647],
	"test_x_pos_64": ["%-*.*x]", 0, 0, 2147483647],
	"test_bigX_zero": ["%X]", 0],
	"test_bigX_neg_01": ["%0X]", -2147483647],
	"test_bigX_neg_02": ["%0.0X]", -2147483647],
	"test_bigX_neg_03": ["%.0X]", -2147483647],
	"test_bigX_neg_04": ["%25X]", -2147483647],
	"test_bigX_neg_05": ["%025.0X]", -2147483647],
	"test_bigX_neg_06": ["%25.0X]", -2147483647],
	"test_bigX_neg_07": ["%-25.0X]", -2147483647],
    "test_bigX_neg_08": ["%-5.0X]", -2147483647],
	"test_bigX_neg_09": ["%.5X]", -2147483647],
	"test_bigX_neg_10": ["%-5.5X]", -2147483647],
	"test_bigX_neg_11": ["%0.25X]", -2147483647],
	"test_bigX_neg_12": ["%.25X]", -2147483647],
	"test_bigX_neg_13": ["%-5.25X]", -2147483647],
	"test_bigX_neg_14": ["%025.25X]", -2147483647],
    "test_bigX_neg_15": ["%25.25X]", -2147483647],
	"test_bigX_neg_16": ["%-25.25X]", -2147483647],
	"test_bigX_neg_17": ["%5X]", -2147483647],
	"test_bigX_neg_18": ["%05.0X]", -2147483647],
	"test_bigX_neg_19": ["%5.0X]", -2147483647],
	"test_bigX_neg_20": ["%05.5X]", -2147483647],
	"test_bigX_neg_22": ["%5.5X]", -2147483647],
	"test_bigX_neg_23": ["%.25X]", -2147483647],
	"test_bigX_neg_24": ["%25u]", -2147483647],
	"test_bigX_neg_25": ["%025X]", -2147483647],
	"test_bigX_neg_26": ["%.*X]", 0, -2147483647],
	"test_bigX_neg_27": ["%.*X]", 25, -2147483647],
	"test_bigX_neg_28": ["%.*X]", -25, -2147483647],
	"test_bigX_neg_29": ["%*X]", 25, -2147483647],
	"test_bigX_neg_30": ["%*X]", -25, -2147483647],
	"test_bigX_neg_31": ["%25.*X]", 25, -2147483647],
	"test_bigX_neg_32": ["%25.*X]", -25, -2147483647],
	"test_bigX_neg_33": ["%-25.*X]", -25, -2147483647],
	"test_bigX_neg_34": ["%-25.*X]", 25, -2147483647],
	"test_bigX_neg_35": ["%025.*X]", -25, -2147483647],
	"test_bigX_neg_36": ["%025.*X]", 25, -2147483647],
	"test_bigX_neg_37": ["%*.0X]", -25, -2147483647],
	"test_bigX_neg_38": ["%*.0X]", 25, -2147483647],
	"test_bigX_neg_39": ["%*.25X]", -25, -2147483647],
	"test_bigX_neg_40": ["%*.25X]", 25, -2147483647],
	"test_bigX_neg_41": ["%-*.25X]", -25, -2147483647],
	"test_bigX_neg_42": ["%-*.25X]", 25, -2147483647],
	"test_bigX_neg_43": ["%0*.25X]", -25, -2147483647],
	"test_bigX_neg_44": ["%0*.25X]", 25, -2147483647],
	"test_bigX_neg_45": ["%-*.*X]", -25, 25, -2147483647],
	"test_bigX_neg_46": ["%-*.*X]", 25, -25, -2147483647],
	"test_bigX_neg_47": ["%-*.*X]", 25, 25, -2147483647],
	"test_bigX_neg_48": ["%-*.*X]", -25, -25, -2147483647],
	"test_bigX_neg_49": ["%*.*X]", 0, -25, -2147483647],
	"test_bigX_neg_50": ["%*.*X]", 0, 25, -2147483647],
	"test_bigX_neg_51": ["%*.*X]", 0, 0, -2147483647],
	"test_bigX_neg_52": ["%*.*X]", -25, 0, -2147483647],
	"test_bigX_neg_53": ["%*.*X]", 25, 0, -2147483647],
	"test_bigX_neg_54": ["%0*.*X]", 25, 0, -2147483647],
	"test_bigX_neg_55": ["%0*.*X]", 0, 25, -2147483647],
	"test_bigX_neg_56": ["%0*.*X]", 0, -25, -2147483647],
	"test_bigX_neg_57": ["%0*.*X]", -25, 0, -2147483647],
	"test_bigX_neg_58": ["%0*.*X]", 0, 0, -2147483647],
	"test_bigX_neg_59": ["%-*.*X]", 0, 0, -2147483647],
	"test_bigX_neg_60": ["%-*.*X]", 25, 0, -2147483647],
	"test_bigX_neg_61": ["%-*.*X]", 0, 25, -2147483647],
	"test_bigX_neg_62": ["%-*.*X]", 0, -25, -2147483647],
	"test_bigX_neg_63": ["%-*.*X]", -25, 0, -2147483647],
	"test_bigX_pos_01": ["%0X]", 2147483647],
	"test_bigX_pos_02": ["%0.0X]", 2147483647],
	"test_bigX_pos_03": ["%.0X]", 2147483647],
	"test_bigX_pos_04": ["%25X]", 2147483647],
	"test_bigX_pos_05": ["%025.0X]", 2147483647],
	"test_bigX_pos_06": ["%25.0X]", 2147483647],
	"test_bigX_pos_07": ["%-25.0X]", 2147483647],
    "test_bigX_pos_08": ["%-5.0X]", 2147483647],
	"test_bigX_pos_09": ["%.5X]", 2147483647],
	"test_bigX_pos_10": ["%-5.5X]", 2147483647],
	"test_bigX_pos_11": ["%0.25X]", 2147483647],
	"test_bigX_pos_12": ["%.25X]", 2147483647],
	"test_bigX_pos_13": ["%-5.25X]", 2147483647],
	"test_bigX_pos_14": ["%025.25X]", 2147483647],
    "test_bigX_pos_15": ["%25.25X]", 2147483647],
	"test_bigX_pos_16": ["%-25.25X]", 2147483647],
	"test_bigX_pos_17": ["%5X]", 2147483647],
	"test_bigX_pos_18": ["%05.0X]", 2147483647],
	"test_bigX_pos_19": ["%5.0X]", 2147483647],
	"test_bigX_pos_20": ["%05.5X]", 2147483647],
	"test_bigX_pos_22": ["%5.5X]", 2147483647],
	"test_bigX_pos_23": ["%.25X]", 2147483647],
	"test_bigX_pos_24": ["%25X]", 2147483647],
	"test_bigX_pos_25": ["%025X]", 2147483647],
	"test_bigX_pos_26": ["%.*X]", 0, 2147483647],
	"test_bigX_pos_27": ["%.*X]", 25, 2147483647],
	"test_bigX_pos_28": ["%.*X]", -25, 2147483647],
	"test_bigX_pos_29": ["%*X]", 25, 2147483647],
	"test_bigX_pos_30": ["%*X]", -25, 2147483647],
	"test_bigX_pos_31": ["%25.*X]", 25, 2147483647],
	"test_bigX_pos_32": ["%25.*X]", -25, 2147483647],
	"test_bigX_pos_33": ["%-25.*X]", -25, 2147483647],
	"test_bigX_pos_34": ["%-25.*X]", 25, 2147483647],
	"test_bigX_pos_35": ["%025.*X]", -25, 2147483647],
	"test_bigX_pos_36": ["%025.*X]", 25, 2147483647],
	"test_bigX_pos_37": ["%*.0X]", -25, 2147483647],
	"test_bigX_pos_38": ["%*.0X]", 25, 2147483647],
	"test_bigX_pos_39": ["%*.25X]", -25, 2147483647],
	"test_bigX_pos_40": ["%*.25X]", 25, 2147483647],
	"test_bigX_pos_41": ["%-*.25X]", -25, 2147483647],
	"test_bigX_pos_42": ["%-*.25X]", 25, 2147483647],
	"test_bigX_pos_43": ["%0*.25X]", -25, 2147483647],
	"test_bigX_pos_44": ["%0*.25X]", 25, 2147483647],
	"test_bigX_pos_45": ["%-*.*X]", -25, 25, 2147483647],
	"test_bigX_pos_46": ["%-*.*X]", 25, -25, 2147483647],
	"test_bigX_pos_47": ["%-*.*X]", 25, 25, 2147483647],
	"test_bigX_pos_48": ["%-*.*X]", -25, -25, 2147483647],
	"test_bigX_pos_49": ["%*.*X]", 0, -25, 2147483647],
	"test_bigX_pos_50": ["%*.*X]", 0, 25, 2147483647],
	"test_bigX_pos_51": ["%*.*X]", 0, 0, 2147483647],
	"test_bigX_pos_52": ["%*.*X]", -25, 0, 2147483647],
	"test_bigX_pos_53": ["%*.*X]", 25, 0, 2147483647],
	"test_bigX_pos_54": ["%0*.*X]", 25, 0, 2147483647],
	"test_bigX_pos_55": ["%0*.*X]", 0, 25, 2147483647],
	"test_bigX_pos_56": ["%0*.*X]", 0, -25, 2147483647],
	"test_bigX_pos_57": ["%0*.*X]", -25, 0, 2147483647],
	"test_bigX_pos_58": ["%0*.*X]", 0, 0, 2147483647],
	"test_bigX_pos_59": ["%-*.*X]", 0, 0, 2147483647],
	"test_bigX_pos_60": ["%-*.*X]", 25, 0, 2147483647],
	"test_bigX_pos_61": ["%-*.*X]", 0, 25, 2147483647],
	"test_bigX_pos_62": ["%-*.*X]", 0, -25, 2147483647],
	"test_bigX_pos_63": ["%-*.*X]", -25, 0, 2147483647],
	"test_bigX_pos_64": ["%-*.*X]", 0, 0, 2147483647],
	"test_char_c_00": ["%c]", 0],
	"test_char_c_01": ["%c]", 'c'],
	"test_char_c_02": ["%-10c]", 'c'],
	"test_char_c_03": ["%-1c]", 'c'],
	"test_char_c_04": ["%10c]", 'c'],
	"test_char_c_05": ["%1c]", 'c'],
	"test_char_c_06": ["%-4c]", 'c'],
	"test_char_c_07": ["%*c]", 0, 'c'],
	"test_char_c_08": ["%-*c]", 100, 'c'],
	"test_char_c_09": ["%-*c]", -40, 'c'],
	"test_char_c_10": ["%*c]", -94, 'c'],
	"test_char_c_11": ["%*c]", 10, 'c'],
	"test_char_c_12": ["%-*c]", 0, 'c'],
	"test_string_01": ["%s]", "qwerty"],
	"test_string_02": ["%-10s]", "qwerty"],
	"test_string_03": ["%10s]", "qwerty"],
	"test_string_04": ["%-4s]", "qwerty"],
	"test_string_05": ["%4s]", "qwerty"],
	"test_string_06": ["%-10.4s]", "qwerty"],
	"test_string_07": ["%10.4s]", "qwerty"],
	"test_string_08": ["%-4.10s]", "qwerty"],
	"test_string_09": ["%4.10s]", "qwerty"],
	"test_string_10": ["%.4s]", "qwerty"],
	"test_string_11": ["%1.4s]", "qwerty"],
	"test_string_12": ["%4.1s]", "qwerty"],
	"test_string_13": ["%.0s]", "qwerty"],
	"test_string_14": ["%4.0s]", "qwerty"],
	"test_string_15": ["%10.0s]", "qwerty"],
	"test_string_16": ["%25s]", "qwerty"],
	"test_string_17": ["%25.25s]", "qwerty"],
	"test_string_18": ["%1.0s]", "qwerty"],
	"test_string_19": ["%*s]", -45, "qwerty"],
	"test_string_20": ["%-*s]", -78, "qwerty"],
	"test_string_21": ["%.*s]",0, "qwerty"],
	"test_string_22": ["%*.*s]", 25, -25, "qwerty"],
	"test_string_23": ["%.*s]", 2, "qwerty"],
	"test_string_24": ["%*.*s]", 0, 0, "qwerty"],
	"test_string_25": ["%*.*s]", 25, -25, "qwerty"],
	"test_string_26": ["%*.*s]", 25, -25, ""],
	"test_string_27": ["%*.*s]", 0, 0, ""],
	"test_percent_01": ["%0%]"],
	"test_percent_02": ["%0.0%]"],
	"test_percent_03": ["%.0%]"],
	"test_percent_04": ["%25%]"],
	"test_percent_05": ["%025.0%]"],
	"test_percent_06": ["%25.0%]"],
	"test_percent_07": ["%-25.0%]"],
    "test_percent_08": ["%-5.0%]"],
	"test_percent_09": ["%.5%]"],
	"test_percent_10": ["%-5.5%]"],
	"test_percent_11": ["%0.25%]"],
	"test_percent_12": ["%.25%]"],
	"test_percent_13": ["%-5.25%]"],
	"test_percent_14": ["%025.25%]"],
    "test_percent_15": ["%25.25%]"],
	"test_percent_16": ["%-25.25%]"],
	"test_percent_17": ["%5%]"],
	"test_percent_18": ["%05.0%]"],
	"test_percent_19": ["%5.0%]"],
	"test_percent_20": ["%05.5%]"],
	"test_percent_21": ["%5.5%]"],
	"test_percent_22": ["%.25%]"],
	"test_percent_23": ["%-025.25%]"],
	"test_percent_24": ["%%]"],
	"test_percent_25": ["%25%]"],
	"test_percent_26": ["%025%]"],
	"test_percent_27": ["%.*%]", 15],
	"test_percent_28": ["%.*%]", -15],
	"test_percent_29": ["%*%]", 15],
	"test_percent_30": ["%*%]", -15],
	"test_percent_31": ["%25.*%]", 2],
	"test_percent_32": ["%25.*%]", 30],
	"test_percent_33": ["%-25.*%]", -30],
	"test_percent_34": ["%-25.*%]", 12],
	"test_percent_35": ["%025.*%]", 1],
	"test_percent_36": ["%025.*%]", 30],
	"test_percent_37": ["%*.0%]", 0],
	"test_percent_38": ["%*.0%]", 25],
	"test_percent_39": ["%*.25%]", 25],
	"test_percent_40": ["%*.25%]", -25],
	"test_percent_41": ["%-*.25%]", 5],
	"test_percent_42": ["%-*.25%]", 40],
	"test_percent_43": ["%0*.25%]", 2],
	"test_percent_44": ["%0*.25%]", 30],
	"test_percent_45": ["%-*.*%]", -45, 45],
	"test_percent_46": ["%-*.*%]", 45, 3],
	"test_percent_47": ["%-*.*%]", 12, 45],
	"test_percent_48": ["%-*.*%]", 12, -45],
	"test_percent_49": ["%*.*%]", 52, 0],
	"test_percent_50": ["%*.*%]", 12, -12],
	"test_percent_51": ["%*.*%]", 12, -45],
	"test_percent_52": ["%*.*%]", 12, 45],
	"test_percent_53": ["%*.*%]", 0, 0],
	"test_percent_54": ["%0*.*%]", 12, -45],
	"test_percent_55": ["%0*.*%]", -45, 12],
	"test_percent_56": ["%0*.*%]", -45, -45],
	"test_percent_57": ["%0*.*%]", 42, 12],
	"test_percent_58": ["%0*.*%]", 12, 42],
	"test_percent_59": ["%-*.*%]",3, 3],
	"test_percent_60": ["%-*.*%]", -3, -3],
	"test_percent_61": ["%-*.*%]", 3, -3],
	"test_percent_62": ["%-*.*%]", -3, 3],
	"test_percent_63": ["%-*.*%]", 100, 200],
	"test_percent_64": ["%-*.*%]", 200, 100],
	"test_total_random_01": ["%12d%*u", 0, 12, 98745],
	"test_total_random_02": ["%d %%", 20],
	"test_total_random_03": ["%*.*d %%",12, 2, 564450],
	"test_total_random_04": ["%.6s%-89c", "qwertyuiop", 'c'],
	"test_total_random_05": ["%%%%%%%%%%%%%%%%%%"],
	"test_total_random_06": ["%x %0*.*duhrgy%%", -467522, 45, -45, -6],
	"test_total_random_07": ["cestla%-*.65s", 690, "fete"],
	"test_total_random_08": ["%000.45d", 12],
	"test_total_random_09": ["%4.1d]", 578630],
	"test_total_random_10": ["%-48.*s]", -9, "lol"],
	"test_total_random_11": ["%0*xduvio", -24, -42168],
	"test_total_random_12": ["%%%.74d", 57523],
	"test_total_random_13": ["%-54.12s", "9qwertyu87823"],
	"test_total_random_14": ["%-*.*d", -30, -25, 0],
	"test_total_random_15": ["%0*.*d", 11, 0, 0],
	"test_int_random_01": ["%12d]", 0],
	"test_int_random_02": ["%5.42d]", 20],
	"test_int_random_03": ["%.85d]", 564450],
	"test_int_random_04": ["%3d]", 4878620],
	"test_int_random_05": ["%075.45d]", -5420],
	"test_int_random_06": ["%12.69d]", -467522],
	"test_int_random_07": ["%-14.85d]", 690],
	"test_int_random_08": ["%-5.87d]", 621],
	"test_int_random_09": ["%.12d]", 578630],
	"test_int_random_10": ["%-3.78d]", -9],
	"test_int_random_11": ["%0.97d]", 42168],
	"test_int_random_12": ["%.74d]", 57523],
	"test_int_random_13": ["%-54.12d]", 0],
	"test_int_random_14": ["%02.87d]", -90],
	"test_int_random_15": ["%1.1d]", 2],
	"test_int_random_16": ["%078.4d]", 2],
	"test_int_random_17": ["%5.87d]", 21],
	"test_int_random_18": ["%-11.11d]", 9870],
	"test_int_random_19": ["%0d]", -0],
	"test_int_random_20": ["%012.45d]", 9785],
	"test_int_random_21": ["%52.0d]", -1],
	"test_int_random_22": ["%05.52d]", 54874],
	"test_int_random_23": ["%57.59d]", 12 - 4],
	"test_int_random_24": ["%.1d]", 789542],
	"test_int_random_24": ["%5d]", 6487],
	"test_int_random_25": ["%045d]", 54],
	"test_all_mixedup_01": ["%25%], [%-12u], [%12.5s], [%-4c], [%21.6d], [%0u], [%-5d]", 12, "qwerty", 'X', 12, 45678965, -6],
	"test_all_mixedup_02": ["%12.*s], [%-4c], [%21.6d], [%0u],  [%-*x], [%-5d],", 3, "qwerty", 'X', 12, 45678965, -6, 14, 456],
	"test_all_mixedup_03": ["qwerty [%1.2s], [%087c], [%21.62s], [%087u],  [%-*x], [%-1.*d],", 3, "qwerty", 'X', 12, 0, -6, 14, 456, 45],
	"test_all_mixedup_04": ["%% qwerty [%1.*s], [%8c], [%*.6d], [%% %u],  [%-*x], [%-8.*d],", 3, "qwerty", 'X', 5, 12, 45678965, -6, 14, 456, 45],
}






MAIN_FILE = """
#include "ft_printf.h"

int main()
{{
    ft_printf({});
}}
"""

MAIN_TEMOIN = """
#include <stdio.h>

int main()
{{
    printf({});
}}
"""



def c_repr(vrepr):
    # attention les char* de len un seront des char.
    if isinstance(vrepr, str) and len(vrepr) > 1:
        return '"{}"'.format(vrepr)
    return repr(vrepr)


def all_repr(to_repr):
    return " ".join([repr(x) for x in to_repr])


def get_printf_args(list_arg):
    return ', '.join([c_repr(x) for x in list_arg])


def create_main(filename, printf_args):
    temoin = filename + '_temoin.c'
    filename += '.c'
    content = MAIN_FILE.format(printf_args)
    # print(content)
    with open(filename, 'w+') as stream:
        stream.write(content)
        stream.close()
    content = MAIN_TEMOIN.format(printf_args)
    with open(temoin, 'w+') as stream:
        stream.write(content)
        stream.close()
    return filename, temoin


def compile_main(filename, printf_args):
    filenamec, temoin = create_main(filename, printf_args)
    # faut pas hésiter à ajouter vos lib et vos header et vos sources ...
    ret = os.system(
        "gcc {filename} -Wall -Werror -Wextra srcs/*/*.o -Iincludes libft/libft.a -o {out}".format(filename=filenamec, out=filename))
    ret += os.system(
        "gcc {filename} -Wall -Werror -Wextra srcs/*/*.o -Iincludes libft/libft.a -o {out}".format(filename=temoin, out=filename + '_temoin'))
    if ret:
        print("Error: compilation on file {}".format(filename))


def compare(exec, repr_args):
    os.system("./{} > one; ".format(exec))
    os.system("./{} > two;".format(exec + '_temoin'))
    os.system("diff one two > {}.test".format(exec))
    diff = open("one").read() == open("two").read()
    os.system("rm one two")
    if not diff:
        print("\x1b[31mUnit Error [FAIL]: {} \033[0;37m".format(exec))
        os.system("cat {}.test".format(exec))
        print("")
    else:
        print("\x1b[32mPassed Test [OK]: {} \033[0;37m".format(exec))
        os.system("rm {exec}_temoin {exec} {exec}.test {exec}.c {exec}_temoin.c 2>&-".format(exec=exec))


def unit_test(dict_test):
    for key in dict_test:
        value = get_printf_args(dict_test[key])
        compile_main(key, value)
        compare(key, all_repr(dict_test[key]))


def main():
    if len(sys.argv) > 1:
        input_test = {"input_test": sys.argv[1:]}
        unit_test(input_test)
    else:
        unit_test(UNITTEST)


if __name__ == '__main__':
    main()
