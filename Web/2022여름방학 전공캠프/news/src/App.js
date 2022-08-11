import './App.css';
import {useState, useCallback} from 'react';
import NewsList from './components/NewList';
import Categories from './components/Categories';
import { Route, Routes } from 'react-router-dom';
import NewsPage from './pages/NewsPage';

function App() {
  const [category, setCategory] = useState('all');
  const onSelect = useCallback(category => setCategory(category), []);
  return (
    <Routes>
      <Route path='/' element={<NewsPage/>} />
      <Route path='/:category' element={<NewsPage/>} />
    </Routes>
  );
}

export default App;
