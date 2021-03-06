/* This software is distributed under BSD 3-clause license (see LICENSE file).
 *
 * Copyright (c) 2012-2013 Sergey Lisitsyn
 */


#ifndef COVERTREESOLVER_H__
#define COVERTREESOLVER_H__

#include <shogun/lib/config.h>

#include <shogun/lib/common.h>
#include <shogun/distance/Distance.h>
#include <shogun/multiclass/KNNSolver.h>

namespace shogun
{

/**
 * The CoverTreeKNNSolver class is a solver class which inherit from KNNSolver class. 
 * It use the cover tree to speed up the nearest neighbor search and you can find more
 * detail information on https://en.wikipedia.org/wiki/Cover_tree
 *
 */
class CCoverTreeKNNSolver : public CKNNSolver
{
	public:
		/** default constructor */
		CCoverTreeKNNSolver() : CKNNSolver()
		{ /* nothing to do */ }

		/** deconstructor */
		virtual ~CCoverTreeKNNSolver() { /* nothing to do */ }

		/** constructor
		 *
		 * @param k k
		 * @param q m_q
		 * @param num_classes m_num_classes
		 * @param min_label m_min_label
		 * @param train_labels m_train_labels 
		 */
		CCoverTreeKNNSolver(const int32_t k, const float64_t q, const int32_t num_classes, const int32_t min_label, const SGVector<int32_t> train_labels);

		virtual CMulticlassLabels* classify_objects(CDistance* d, const int32_t num_lab, int32_t* train_lab, float64_t* classes) const;

		virtual int32_t* classify_objects_k(CDistance* d, const int32_t num_lab, int32_t* train_lab, int32_t* classes) const;

		/** @return object name */
		const char* get_name() const { return "CoverTreeKNNSolver"; }

};
}

#endif
