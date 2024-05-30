import React, { useState } from 'react';

const Form = () => 
{
  const [form, setForm] = useState({
    userId: '',
    password: '',
    name: '',
    address: '',
    country: '',
    email: '',
    sex: '',
    language: [],
    about: ''
  });

  const [errors, setErrors] = useState({});
  const [touched, setTouched] = useState({});

  const countries = ['USA', 'Canada', 'UK', 'Germany', 'France'];

  const validate = (name, value) => {
    switch (name) 
    {
      case 'userId':
        return value.length >= 5 && value.length <= 7;
      case 'password':
        return value.length >= 7 && value.length <= 12;
      case 'name':
        return /^[A-Za-z]+$/.test(value);
      case 'address':
        return /^[A-Za-z0-9\s]+$/.test(value);
      case 'country':
        return value !== '';
      case 'email':
        return /^[^\s@]+@[^\s@]+\.[^\s@]+$/.test(value);
      case 'sex':
        return value === 'Male' || value === 'Female';
      default:
        return true;
    }
  };

  const handleChange = (e) => {
    const { name, value, type, checked } = e.target;

    if (type === 'checkbox') 
    {
      const newLanguages = checked
        ? [...form.language, value]
        : form.language.filter(lang => lang !== value);
      setForm({
        ...form,
        language: newLanguages
      });
      return;
    }

    setForm({
      ...form,
      [name]: value
    });

    if (touched[name]) 
    {
      setErrors({
        ...errors,
        [name]: !validate(name, value)
      });
    }
  };

  const handleBlur = (e) => {
    const { name, value } = e.target;

    setTouched({
      ...touched,
      [name]: true
    });

    setErrors({
      ...errors,
      [name]: !validate(name, value)
    });
  };

  const handleSubmit = (e) => {
    e.preventDefault();
    const newErrors = Object.keys(form).reduce((acc, key) => {
      acc[key] = !validate(key, form[key]);
      return acc;
    }, {});

    setErrors(newErrors);

    const noErrors = Object.values(newErrors).every(error => !error);

    if (noErrors) 
    {
      alert('Form submitted successfully!');
    } 
    else { alert('Please fix the errors in the form.'); }
  };

  const renderValidationIcon = (field) => {
    if (!touched[field]) return null;
    return errors[field] ? (
      <span className="validation-icon error-icon">❌</span>
    ) : (
      <span className="validation-icon success-icon">✔️</span>
    );
  };

  return (
    <form onSubmit={handleSubmit} className="form">
      <div className={`form-group ${errors.userId ? 'error' : ''}`}>
        <label>User id [5 to 7 characters]: </label>
        <div className="input-wrapper">
          <input
            type="text"
            name="userId"
            value={form.userId}
            onChange={handleChange}
            onBlur={handleBlur}
          />
          {renderValidationIcon('userId')}
        </div>
      </div>
      
      <div className={`form-group ${errors.password ? 'error' : ''}`}>
        <label>Password [7 to 12 characters]: </label>
        <div className="input-wrapper">
          <input
            type="password"
            name="password"
            value={form.password}
            onChange={handleChange}
            onBlur={handleBlur}
          />
          {renderValidationIcon('password')}
        </div>
      </div>

      <div className={`form-group ${errors.name ? 'error' : ''}`}>
        <label>Name [Alphabets characters]: </label>
        <div className="input-wrapper">
          <input
            type="text"
            name="name"
            value={form.name}
            onChange={handleChange}
            onBlur={handleBlur}
          />
          {renderValidationIcon('name')}
        </div>
      </div>

      <div className={`form-group ${errors.address ? 'error' : ''}`}>
        <label>Address [alphanumeric characters]: </label>
        <div className="input-wrapper">
          <input
            type="text"
            name="address"
            value={form.address}
            onChange={handleChange}
            onBlur={handleBlur}
          />
          {renderValidationIcon('address')}
        </div>
      </div>

      <div className={`form-group ${errors.country ? 'error' : ''}`}>
        <label>Country [Must select a country]: </label>
        <div className="input-wrapper">
          <select
            name="country"
            value={form.country}
            onChange={handleChange}
            onBlur={handleBlur}
          >
            <option value="">Select a country</option>
            {countries.map(country => (
              <option key={country} value={country}>{country}</option>
            ))}
          </select>
          {renderValidationIcon('country')}
        </div>
      </div>

      <div className={`form-group ${errors.email ? 'error' : ''}`}>
        <label>Email [Valid email]: </label>
        <div className="input-wrapper">
          <input
            type="email"
            name="email"
            value={form.email}
            onChange={handleChange}
            onBlur={handleBlur}
          />
          {renderValidationIcon('email')}
        </div>
      </div>

      <div className={`form-group ${errors.sex ? 'error' : ''}`}>
        <label>Sex [Select Male or Female]: </label>
        <div className="input-wrapper">
          <label>
            <input
              type="radio"
              name="sex"
              value="Male"
              checked={form.sex === 'Male'}
              onChange={handleChange}
              onBlur={handleBlur}
            /> Male
          </label>
          <label>
            <input
              type="radio"
              name="sex"
              value="Female"
              checked={form.sex === 'Female'}
              onChange={handleChange}
              onBlur={handleBlur}
            /> Female
          </label>
          {renderValidationIcon('sex')}
        </div>
      </div>

      <div className="form-group">
        <label>Language [Optional]: </label>
        <div className="input-wrapper">
          <label>
            <input
              type="checkbox"
              name="language"
              value="English"
              checked={form.language.includes('English')}
              onChange={handleChange}
            /> English
          </label>
          <label>
            <input
              type="checkbox"
              name="language"
              value="Non English"
              checked={form.language.includes('Non English')}
              onChange={handleChange}
            /> Non English
          </label>
        </div>
      </div>

      <div className="form-group">
        <label>About:</label>
        <textarea
          name="about"
          value={form.about}
          onChange={handleChange}
        />
      </div>

      <button type="submit">Submit</button>
    </form>
  );
};

export default Form;
