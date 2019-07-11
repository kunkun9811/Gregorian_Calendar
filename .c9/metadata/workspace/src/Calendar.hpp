{"changed":true,"filter":false,"title":"Calendar.hpp","tooltip":"/src/Calendar.hpp","value":"/* Calendar Class\n * \n * Input: A specific year in Gregorian Calendar\n * Output: Creates an object for a specific year (Gregorian Calendar)\n * \n * 1/24/19  = First Started\n *\n */\n \n#ifndef Calendar.hpp\n#define Calendar.hpp\n\n#include <iostream>\n\ntemplate <typename T>\nclass Calendar {\n    protected:\n        monthNode *monthsRoot;\n        monthNode *jan;\n        monthNode *february;\n        monthNode *march;\n        monthNode *april;\n        monthNode *may;\n        monthNode *june;\n        monthNode *july;\n        monthNode *august;\n        monthNode *september;\n        monthNode *october;\n        monthNode *november;\n        monthNode *december;\n    public:\n        Calendar() {\n            \n        }\n    \n};","undoManager":{"mark":-193,"position":100,"stack":[[{"start":{"row":22,"column":20},"end":{"row":22,"column":21},"action":"insert","lines":["r"],"id":1022}],[{"start":{"row":22,"column":21},"end":{"row":22,"column":22},"action":"insert","lines":["i"],"id":1023}],[{"start":{"row":22,"column":22},"end":{"row":22,"column":23},"action":"insert","lines":["d"],"id":1024}],[{"start":{"row":22,"column":23},"end":{"row":22,"column":24},"action":"insert","lines":["a"],"id":1025}],[{"start":{"row":22,"column":24},"end":{"row":22,"column":25},"action":"insert","lines":["y"],"id":1026}],[{"start":{"row":23,"column":21},"end":{"row":23,"column":22},"action":"remove","lines":["n"],"id":1027}],[{"start":{"row":23,"column":20},"end":{"row":23,"column":21},"action":"remove","lines":["a"],"id":1028}],[{"start":{"row":23,"column":19},"end":{"row":23,"column":20},"action":"remove","lines":["J"],"id":1029}],[{"start":{"row":23,"column":19},"end":{"row":23,"column":20},"action":"insert","lines":["S"],"id":1030}],[{"start":{"row":23,"column":20},"end":{"row":23,"column":21},"action":"insert","lines":["a"],"id":1031}],[{"start":{"row":23,"column":21},"end":{"row":23,"column":22},"action":"insert","lines":["y"],"id":1032},{"start":{"row":23,"column":22},"end":{"row":23,"column":23},"action":"insert","lines":["t"]}],[{"start":{"row":23,"column":22},"end":{"row":23,"column":23},"action":"remove","lines":["t"],"id":1033}],[{"start":{"row":20,"column":19},"end":{"row":20,"column":28},"action":"remove","lines":["Wednesday"],"id":1034},{"start":{"row":20,"column":19},"end":{"row":20,"column":20},"action":"insert","lines":["M"]}],[{"start":{"row":20,"column":20},"end":{"row":20,"column":21},"action":"insert","lines":["a"],"id":1035}],[{"start":{"row":20,"column":21},"end":{"row":20,"column":22},"action":"insert","lines":["r"],"id":1036}],[{"start":{"row":20,"column":22},"end":{"row":20,"column":23},"action":"insert","lines":["c"],"id":1037}],[{"start":{"row":20,"column":23},"end":{"row":20,"column":24},"action":"insert","lines":["h"],"id":1038}],[{"start":{"row":21,"column":19},"end":{"row":21,"column":27},"action":"remove","lines":["Thursday"],"id":1039},{"start":{"row":21,"column":19},"end":{"row":21,"column":20},"action":"insert","lines":["A"]}],[{"start":{"row":21,"column":20},"end":{"row":21,"column":21},"action":"insert","lines":["p"],"id":1040}],[{"start":{"row":21,"column":21},"end":{"row":21,"column":22},"action":"insert","lines":["r"],"id":1041}],[{"start":{"row":21,"column":22},"end":{"row":21,"column":23},"action":"insert","lines":["i"],"id":1042}],[{"start":{"row":21,"column":23},"end":{"row":21,"column":24},"action":"insert","lines":["l"],"id":1043}],[{"start":{"row":22,"column":19},"end":{"row":22,"column":25},"action":"remove","lines":["Friday"],"id":1044},{"start":{"row":22,"column":19},"end":{"row":22,"column":20},"action":"insert","lines":["<"]}],[{"start":{"row":22,"column":19},"end":{"row":22,"column":20},"action":"remove","lines":["<"],"id":1045}],[{"start":{"row":22,"column":19},"end":{"row":22,"column":20},"action":"insert","lines":["M"],"id":1046}],[{"start":{"row":22,"column":20},"end":{"row":22,"column":21},"action":"insert","lines":["a"],"id":1047}],[{"start":{"row":22,"column":21},"end":{"row":22,"column":22},"action":"insert","lines":["y"],"id":1048}],[{"start":{"row":23,"column":19},"end":{"row":23,"column":22},"action":"remove","lines":["Say"],"id":1049},{"start":{"row":23,"column":19},"end":{"row":23,"column":20},"action":"insert","lines":["J"]}],[{"start":{"row":23,"column":20},"end":{"row":23,"column":21},"action":"insert","lines":["u"],"id":1050}],[{"start":{"row":23,"column":21},"end":{"row":23,"column":22},"action":"insert","lines":["n"],"id":1051}],[{"start":{"row":23,"column":22},"end":{"row":23,"column":23},"action":"insert","lines":["e"],"id":1052}],[{"start":{"row":24,"column":19},"end":{"row":24,"column":22},"action":"remove","lines":["Jan"],"id":1053},{"start":{"row":24,"column":19},"end":{"row":24,"column":20},"action":"insert","lines":["J"]}],[{"start":{"row":24,"column":20},"end":{"row":24,"column":21},"action":"insert","lines":["u"],"id":1054}],[{"start":{"row":24,"column":21},"end":{"row":24,"column":22},"action":"insert","lines":["l"],"id":1055}],[{"start":{"row":24,"column":22},"end":{"row":24,"column":23},"action":"insert","lines":["y"],"id":1056}],[{"start":{"row":25,"column":19},"end":{"row":25,"column":22},"action":"remove","lines":["Jan"],"id":1057},{"start":{"row":25,"column":19},"end":{"row":25,"column":20},"action":"insert","lines":["A"]}],[{"start":{"row":25,"column":20},"end":{"row":25,"column":21},"action":"insert","lines":["u"],"id":1058}],[{"start":{"row":25,"column":21},"end":{"row":25,"column":22},"action":"insert","lines":["g"],"id":1059}],[{"start":{"row":25,"column":22},"end":{"row":25,"column":23},"action":"insert","lines":["u"],"id":1060}],[{"start":{"row":25,"column":23},"end":{"row":25,"column":24},"action":"insert","lines":["s"],"id":1061}],[{"start":{"row":25,"column":24},"end":{"row":25,"column":25},"action":"insert","lines":["t"],"id":1062}],[{"start":{"row":26,"column":19},"end":{"row":26,"column":22},"action":"remove","lines":["Jan"],"id":1063},{"start":{"row":26,"column":19},"end":{"row":26,"column":20},"action":"insert","lines":["S"]}],[{"start":{"row":26,"column":20},"end":{"row":26,"column":21},"action":"insert","lines":["e"],"id":1064}],[{"start":{"row":26,"column":21},"end":{"row":26,"column":22},"action":"insert","lines":["p"],"id":1065}],[{"start":{"row":26,"column":22},"end":{"row":26,"column":23},"action":"insert","lines":["t"],"id":1066}],[{"start":{"row":26,"column":23},"end":{"row":26,"column":24},"action":"insert","lines":["e"],"id":1067}],[{"start":{"row":26,"column":24},"end":{"row":26,"column":25},"action":"insert","lines":["m"],"id":1068}],[{"start":{"row":26,"column":25},"end":{"row":26,"column":26},"action":"insert","lines":["b"],"id":1069}],[{"start":{"row":26,"column":26},"end":{"row":26,"column":27},"action":"insert","lines":["e"],"id":1070}],[{"start":{"row":26,"column":27},"end":{"row":26,"column":28},"action":"insert","lines":["r"],"id":1071}],[{"start":{"row":27,"column":19},"end":{"row":27,"column":22},"action":"remove","lines":["Jan"],"id":1072},{"start":{"row":27,"column":19},"end":{"row":27,"column":20},"action":"insert","lines":["o"]}],[{"start":{"row":27,"column":20},"end":{"row":27,"column":21},"action":"insert","lines":["c"],"id":1073}],[{"start":{"row":27,"column":21},"end":{"row":27,"column":22},"action":"insert","lines":["t"],"id":1074}],[{"start":{"row":27,"column":22},"end":{"row":27,"column":23},"action":"insert","lines":["o"],"id":1075}],[{"start":{"row":27,"column":23},"end":{"row":27,"column":24},"action":"insert","lines":["b"],"id":1076}],[{"start":{"row":27,"column":24},"end":{"row":27,"column":25},"action":"insert","lines":["e"],"id":1077}],[{"start":{"row":27,"column":25},"end":{"row":27,"column":26},"action":"insert","lines":["r"],"id":1078}],[{"start":{"row":28,"column":19},"end":{"row":28,"column":22},"action":"remove","lines":["Jan"],"id":1079},{"start":{"row":28,"column":19},"end":{"row":28,"column":20},"action":"insert","lines":["n"]}],[{"start":{"row":28,"column":20},"end":{"row":28,"column":21},"action":"insert","lines":["o"],"id":1080}],[{"start":{"row":28,"column":21},"end":{"row":28,"column":22},"action":"insert","lines":["v"],"id":1081}],[{"start":{"row":28,"column":22},"end":{"row":28,"column":23},"action":"insert","lines":["e"],"id":1082}],[{"start":{"row":28,"column":23},"end":{"row":28,"column":24},"action":"insert","lines":["m"],"id":1083}],[{"start":{"row":28,"column":24},"end":{"row":28,"column":25},"action":"insert","lines":["b"],"id":1084}],[{"start":{"row":28,"column":25},"end":{"row":28,"column":26},"action":"insert","lines":["e"],"id":1085}],[{"start":{"row":28,"column":26},"end":{"row":28,"column":27},"action":"insert","lines":["r"],"id":1086}],[{"start":{"row":29,"column":19},"end":{"row":29,"column":22},"action":"remove","lines":["Jan"],"id":1087},{"start":{"row":29,"column":19},"end":{"row":29,"column":20},"action":"insert","lines":["d"]}],[{"start":{"row":29,"column":20},"end":{"row":29,"column":21},"action":"insert","lines":["e"],"id":1088}],[{"start":{"row":29,"column":21},"end":{"row":29,"column":22},"action":"insert","lines":["c"],"id":1089}],[{"start":{"row":29,"column":22},"end":{"row":29,"column":23},"action":"insert","lines":["e"],"id":1090}],[{"start":{"row":29,"column":23},"end":{"row":29,"column":24},"action":"insert","lines":["m"],"id":1091}],[{"start":{"row":29,"column":24},"end":{"row":29,"column":25},"action":"insert","lines":["b"],"id":1092}],[{"start":{"row":29,"column":25},"end":{"row":29,"column":26},"action":"insert","lines":["e"],"id":1093}],[{"start":{"row":29,"column":26},"end":{"row":29,"column":27},"action":"insert","lines":["r"],"id":1094}],[{"start":{"row":26,"column":19},"end":{"row":26,"column":20},"action":"remove","lines":["S"],"id":1095}],[{"start":{"row":26,"column":19},"end":{"row":26,"column":20},"action":"insert","lines":["s"],"id":1096}],[{"start":{"row":25,"column":19},"end":{"row":25,"column":20},"action":"remove","lines":["A"],"id":1097}],[{"start":{"row":25,"column":19},"end":{"row":25,"column":20},"action":"insert","lines":["a"],"id":1098}],[{"start":{"row":24,"column":19},"end":{"row":24,"column":20},"action":"remove","lines":["J"],"id":1099}],[{"start":{"row":24,"column":19},"end":{"row":24,"column":20},"action":"insert","lines":["j"],"id":1100}],[{"start":{"row":23,"column":20},"end":{"row":23,"column":21},"action":"remove","lines":["u"],"id":1101},{"start":{"row":23,"column":20},"end":{"row":23,"column":21},"action":"insert","lines":["j"]}],[{"start":{"row":23,"column":20},"end":{"row":23,"column":21},"action":"remove","lines":["j"],"id":1102}],[{"start":{"row":23,"column":19},"end":{"row":23,"column":20},"action":"remove","lines":["J"],"id":1103}],[{"start":{"row":23,"column":19},"end":{"row":23,"column":20},"action":"insert","lines":["j"],"id":1104}],[{"start":{"row":22,"column":19},"end":{"row":22,"column":20},"action":"remove","lines":["M"],"id":1105}],[{"start":{"row":22,"column":19},"end":{"row":22,"column":20},"action":"insert","lines":["m"],"id":1106}],[{"start":{"row":21,"column":19},"end":{"row":21,"column":20},"action":"remove","lines":["A"],"id":1107}],[{"start":{"row":21,"column":19},"end":{"row":21,"column":20},"action":"insert","lines":["a"],"id":1108}],[{"start":{"row":20,"column":19},"end":{"row":20,"column":20},"action":"remove","lines":["M"],"id":1109}],[{"start":{"row":20,"column":19},"end":{"row":20,"column":20},"action":"insert","lines":["m"],"id":1110}],[{"start":{"row":19,"column":19},"end":{"row":19,"column":20},"action":"remove","lines":["F"],"id":1111}],[{"start":{"row":19,"column":19},"end":{"row":19,"column":20},"action":"insert","lines":["f"],"id":1112}],[{"start":{"row":18,"column":19},"end":{"row":18,"column":20},"action":"remove","lines":["J"],"id":1113}],[{"start":{"row":18,"column":19},"end":{"row":18,"column":20},"action":"insert","lines":["j"],"id":1114}],[{"start":{"row":18,"column":22},"end":{"row":18,"column":24},"action":"insert","lines":["()"],"id":1115}],[{"start":{"row":18,"column":23},"end":{"row":18,"column":24},"action":"insert","lines":["3"],"id":1116}],[{"start":{"row":18,"column":24},"end":{"row":18,"column":25},"action":"insert","lines":["1"],"id":1117}],[{"start":{"row":18,"column":25},"end":{"row":18,"column":26},"action":"remove","lines":[")"],"id":1118}],[{"start":{"row":18,"column":24},"end":{"row":18,"column":25},"action":"remove","lines":["1"],"id":1119}],[{"start":{"row":18,"column":23},"end":{"row":18,"column":24},"action":"remove","lines":["3"],"id":1120}],[{"start":{"row":18,"column":22},"end":{"row":18,"column":23},"action":"remove","lines":["("],"id":1121}],[{"start":{"row":23,"column":20},"end":{"row":23,"column":21},"action":"insert","lines":["u"],"id":1122}]]},"ace":{"folds":[],"scrolltop":0,"scrollleft":0,"selection":{"start":{"row":12,"column":19},"end":{"row":12,"column":19},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":0},"timestamp":1549613826339}