/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:16:17 by awilliam          #+#    #+#             */
/*   Updated: 2024/08/12 17:10:03 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"
# include "colors.hpp"

class PresidentialPardonForm : public AForm {
private:
    const std::string _target;

public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &oldInstance);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &oldInstance);
    ~PresidentialPardonForm();

    void beSigned(const Bureaucrat &signer);
    virtual void execute(const Bureaucrat &executor) const;
};

#endif