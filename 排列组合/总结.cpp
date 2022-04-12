//  四段论： 边界+tDtD
//	三段论： 边界+for(tDt)
//	有无重复元素，能否重新选择，有重复元素需要去重，重新选择设计depth


//	三段论与树有关，是真正的回溯（直接考虑所有节点）四段论更像递归

//  {a,b,c}的全排列：abc，acb，bac，bca，cab，cba
//  1.abc没有prev_permutation；cba没有next_permutation
//  2.生成的全排列是按照字典顺序进行排列的