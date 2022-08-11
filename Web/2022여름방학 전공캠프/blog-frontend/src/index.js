import React from 'react';
import ReactDOM from 'react-dom/client';
import './index.css';
import App from './App';
import { BrowserRouter } from 'react-router-dom';
import { createStore, applyMiddleware } from 'redux';
import rootReducer, { rootSaga } from './modules/index';
import { composeWithDevTools } from 'redux-devtools-extension';
import { Provider } from 'react-redux';
import createSagaMiddleware from 'redux-saga'
import { check, tempSetUser } from './modules/user';

const sagaMiddleware = createSagaMiddleware();
const store = createStore(rootReducer, composeWithDevTools(applyMiddleware(sagaMiddleware)));

function loadUser() {
  try {
    const user = localStorage.getItem('user');
    if(!user) return;
    store.dispatch(tempSetUser(JSON.parse(user)));
    store.dispatch(check());
  } catch(e) {
    console.log('localStorage is not working');
  }
}
sagaMiddleware.run(rootSaga);
loadUser();

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  <Provider store={store}>
    <BrowserRouter>
      <App />
    </BrowserRouter>
  </Provider>
);
